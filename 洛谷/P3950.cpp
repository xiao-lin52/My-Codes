#include<bits/stdc++.h>
#define MAXN 300001
using namespace std;
struct node
{
	int l;
	int r;
	int data;
};
node tree[MAXN<<2];
vector<int> edge[MAXN];
int n,m,cnt,tot,u[MAXN],v[MAXN],dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
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
	tree[i].data=tree[l].data&tree[r].data;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].data=1;
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
	int ans=1;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	if(tree[i<<1].r>=l)
		ans&=query(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		ans&=query(i<<1|1,l,r);
	return ans;
}
int path_query(int u,int v)
{
	int ans=1;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans&=query(1,id[top[u]],id[u]);
		u=fa[top[u]];
	}
	if(u==v)
		return ans;
	if(dep[son[u]]>dep[v])
		swap(u,v);
	return ans&query(1,id[son[u]],id[v]);
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
		char op;
		int a,b,x;
		cin>>op;
		if(op=='Q')
		{
			scanf("%d%d",&a,&b);
			if(path_query(a,b))
				printf("Yes\n");
			else
				printf("No\n");
		}
		if(op=='C')
		{
			tot++;
			scanf("%d%d",&u[tot],&v[tot]);
			if(dep[u[tot]]<dep[v[tot]])
				swap(u[tot],v[tot]);
			update(1,id[u[tot]],0);
		}
		if(op=='U')
		{
			scanf("%d",&x);
			update(1,id[u[x]],1);
		}
	}
	return 0;
}
