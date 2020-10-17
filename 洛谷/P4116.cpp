#include<bits/stdc++.h>
#define MAXN 100005
#define inf 1e9
using namespace std;
struct node
{
	int l;
	int r;
	int data;
};
node tree[MAXN<<2];
vector<int> edge[MAXN];
int n,m,cnt,dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
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
	tree[i].data=min(tree[l].data,tree[r].data);
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].data=inf;
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	push_up(i);
}
void update(int i,int x)
{
	if(tree[i].l==x&&tree[i].r==x)
	{
		if(tree[i].data==inf)
			tree[i].data=x;
		else
			tree[i].data=inf;
		return;
	}
	if(tree[i<<1].r>=x)
		update(i<<1,x);
	if(tree[i<<1|1].l<=x)
		update(i<<1|1,x);
	push_up(i);
}
int query(int i,int l,int r)
{
	int ans=inf;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	if(tree[i<<1].r>=l)
		ans=min(ans,query(i<<1,l,r));
	if(tree[i<<1|1].l<=r)
		ans=min(ans,query(i<<1|1,l,r));
	return ans;
}
int path_query(int u,int v)
{
	int ans=inf;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans=min(ans,query(1,id[top[u]],id[u]));
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		swap(u,v);
	ans=min(ans,query(1,id[u],id[v]));
	if(ans==inf)
		return -1;
	else
		return rk[ans];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(!op)
			update(1,id[x]);
		else
			printf("%d\n",path_query(1,x));
	}
	return 0;
}
