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
void dfs2(int u,int father,int t)
{
	cnt++;
	rk[cnt]=u;
	id[u]=cnt;
	top[u]=t;
	if(son[u])
		dfs2(son[u],u,t);
	for(int i=0;i<edge[u].size();i++)
		if(edge[u][i]!=father&&edge[u][i]!=son[u])
			dfs2(edge[u][i],u,edge[u][i]);
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		if(rk[l]==1)
			tree[i].data=1;
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	tree[i].data=max(tree[i<<1].data,tree[i<<1|1].data);
}
void update(int i,int x)
{
	if(tree[i].l==x&&tree[i].r==x)
	{
		tree[i].data=x;
		return;
	}
	if(tree[i<<1].r>=x)
		update(i<<1,x);
	if(tree[i<<1|1].l<=x)
		update(i<<1|1,x);
	tree[i].data=max(tree[i<<1].data,tree[i<<1|1].data);
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
int lca_query(int u)
{
	int ans=0;
	do
	{
		ans=max(ans,query(1,id[top[u]],id[u]));
		u=fa[top[u]];
	}
	while(!ans);
	return rk[ans];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		char op;
		int x;
		cin>>op>>x;
		if(op=='C')
			update(1,id[x]);
		else
			cout<<lca_query(x)<<endl;
	}
	return 0;
}
