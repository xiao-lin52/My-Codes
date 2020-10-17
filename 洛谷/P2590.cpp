#include<bits/stdc++.h>
#define MAXN 30001
using namespace std;
struct node
{
	int l;
	int r;
	int sum;
	int maxn;
};
node tree[MAXN<<2];
vector<int> edge[MAXN];
int n,m,cnt,w[MAXN],dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
void dfs1(int u,int father)
{
	dep[u]=dep[father]+1;
	fa[u]=father;
	size[u]=1;
	for(int i=0;i<edge[u].size();i++)
		if(edge[u][i]!=father)
		{
			dfs1(edge[u][i],u);
			size[u]+=size[edge[u][i]];
			son[u]=size[son[u]]>size[edge[u][i]]? son[u]:edge[u][i];
		}
}
void dfs2(int u,int t)
{
	cnt++;
	rk[cnt]=u;
	id[u]=cnt;
	top[u]=t;
	if(son[u])
		dfs2(son[u],t);
	for(int i=0;i<edge[u].size();i++)
		if(edge[u][i]!=fa[u]&&edge[u][i]!=son[u])
			dfs2(edge[u][i],edge[u][i]);
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].sum=tree[i].maxn=w[rk[l]];
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
	tree[i].maxn=max(tree[i<<1].maxn,tree[i<<1|1].maxn);
}
void update(int i,int x,int k)
{
	if(tree[i].l==x&&tree[i].r==x)
	{
		tree[i].sum=tree[i].maxn=k;
		return;
	}
	if(tree[i<<1].r>=x)
		update(i<<1,x,k);
	if(tree[i<<1|1].l<=x)
		update(i<<1|1,x,k);
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
	tree[i].maxn=max(tree[i<<1].maxn,tree[i<<1|1].maxn);
}
int querysum(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].sum;
	if(tree[i<<1].r>=l)
		ans+=querysum(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		ans+=querysum(i<<1|1,l,r);
	return ans;
}
int querymax(int i,int l,int r)
{
	int ans=-1e9;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].maxn;
	if(tree[i<<1].r>=l)
		ans=max(ans,querymax(i<<1,l,r));
	if(tree[i<<1|1].l<=r)
		ans=max(ans,querymax(i<<1|1,l,r));
	return ans;
}
int pathsum(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans+=querysum(1,id[top[u]],id[u]);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		swap(u,v);
	return ans+querysum(1,id[u],id[v]);
}
int pathmax(int u,int v)
{
	int ans=-1e9;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans=max(ans,querymax(1,id[top[u]],id[u]));
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		swap(u,v);
	return max(ans,querymax(1,id[u],id[v]));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		char op[11];
		int u,v;
		scanf("%s%d%d",op,&u,&v);
		if(op[1]=='H')
			update(1,id[u],v);
		if(op[1]=='M')
			printf("%d\n",pathmax(u,v));
		if(op[1]=='S')
			printf("%d\n",pathsum(u,v));
	}
	return 0;
}
