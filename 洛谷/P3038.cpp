#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct node
{
	int l;
	int r;
	int data;
	int f;
};
node tree[MAXN<<2];
vector<int> edge[MAXN];
int n,m,cnt,dep[MAXN],fa[MAXN],size[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
void dfs1(int u,int father)
{
	fa[u]=father;
	dep[u]=dep[father]+1;
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
	top[u]=t;
	rk[cnt]=u;
	id[u]=cnt;
	if(son[u])
		dfs2(son[u],u,t);
	for(int i=0;i<edge[u].size();i++)
		if(edge[u][i]!=son[u]&&edge[u][i]!=father)
			dfs2(edge[u][i],u,edge[u][i]);
}
void push_down(int i)
{
	int l=i<<1,r=i<<1|1;
	if(!tree[i].f)
		return;
	tree[l].data+=tree[i].f*(tree[l].r-tree[l].l+1);
	tree[r].data+=tree[i].f*(tree[r].r-tree[r].l+1);
	tree[l].f+=tree[i].f;
	tree[r].f+=tree[i].f;
	tree[i].f=0;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
		return;
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
}
void update(int i,int l,int r,int k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data+=(tree[i].r-tree[i].l+1)*k;
		tree[i].f+=k;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k);
	tree[i].data=tree[i<<1].data+tree[i<<1|1].data;
}
int query(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans+=query(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		ans+=query(i<<1|1,l,r);
	return ans;
}
void lca_update(int u,int v)
{
	while(top[u]!=top[v])
		if(dep[top[u]]>=dep[top[v]])
		{
			update(1,id[top[u]],id[u],1);
			u=fa[top[u]];
		}
		else
		{
			update(1,id[top[v]],id[v],1);
			v=fa[top[v]];
		}
	if(dep[u]>=dep[v])
		update(1,id[son[v]],id[u],1);
	else
		update(1,id[son[u]],id[v],1);
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
		int x,y;
		cin>>op>>x>>y;
		if(op=='P')
			lca_update(x,y);
		else
			cout<<query(1,dep[x]>dep[y]? id[x]:id[y],dep[x]>dep[y]? id[x]:id[y])<<endl;
	}
	return 0;
}
