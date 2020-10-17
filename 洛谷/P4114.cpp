#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct node
{
	int l;
	int r;
	int data;
};
node tree[MAXN<<2];
vector<int> edge[MAXN];
int n,cnt,u[MAXN],v[MAXN],c[MAXN],w[MAXN];
int dep[MAXN],fa[MAXN],son[MAXN],size[MAXN],rk[MAXN],id[MAXN],top[MAXN];
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
	top[u]=t;
	rk[cnt]=u;
	id[u]=cnt;
	if(son[u])
		dfs2(son[u],t);
	for(int i=0;i<edge[u].size();i++)
		if(edge[u][i]!=fa[u]&&edge[u][i]!=son[u])
			dfs2(edge[u][i],edge[u][i]);
}
void push_up(int i)
{
	int l=i<<1,r=i<<1|1;
	tree[i].data=max(tree[l].data,tree[r].data);
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].data=w[rk[l]];
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	push_up(i);
}
void update(int i,int x,int k)
{
	if(tree[i].l==x&&tree[i].r==x)
	{
		tree[i].data=k;
		return;
	}
	if(tree[i<<1].r>=x)
		update(i<<1,x,k);
	if(tree[i<<1|1].l<=x)
		update(i<<1|1,x,k);
	push_up(i);
}
int query(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	if(tree[i<<1].r>=l)
		ans=max(ans,query(i<<1,l,r));
	if(tree[i<<1|1].l<=r)
		ans=max(ans,query(i<<1|1,l,r));
	return ans;
}
int path_query(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans=max(ans,query(1,id[top[u]],id[u]));
		u=fa[top[u]];
	}
	if(u==v)
		return ans;
	if(dep[u]>dep[v])
		swap(u,v);
	return max(ans,query(1,id[son[u]],id[v]));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
		edge[u[i]].push_back(v[i]);
		edge[v[i]].push_back(u[i]);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n-1;i++)
	{
		if(dep[u[i]]<dep[v[i]])
			swap(u[i],v[i]);
		w[u[i]]=c[i];
	}
	build(1,1,n);
	while(1)
	{
		string op;
		int a,b;
		cin>>op;
		if(op=="DONE")
			break;
		if(op=="CHANGE")
		{
			scanf("%d%d",&a,&b);
			update(1,id[u[a]],b);
		}
		if(op=="QUERY")
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",path_query(a,b));
		}
	}
	return 0;
}
