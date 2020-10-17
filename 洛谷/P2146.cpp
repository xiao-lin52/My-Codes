#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct node
{
	int l;
	int r;
	int data;
	int f=-1;
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
void push_down(int i)
{
	int l=i<<1,r=i<<1|1;
	if(tree[i].f==-1)
		return;
	tree[l].f=tree[i].f;
	tree[r].f=tree[i].f;
	tree[l].data=tree[i].f*(tree[l].r-tree[l].l+1);
	tree[r].data=tree[i].f*(tree[r].r-tree[r].l+1);
	tree[i].f=-1;
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
		tree[i].data=k*(tree[i].r-tree[i].l+1);
		tree[i].f=k;
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
int path(int u,int v)
{
	int ans=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		ans+=(id[u]-id[top[u]]+1)-query(1,id[top[u]],id[u]);
		update(1,id[top[u]],id[u],1);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		swap(u,v);
	ans+=(id[v]-id[u]+1)-query(1,id[u],id[v]);
	update(1,id[u],id[v],1);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int f;
		scanf("%d",&f);
		edge[i].push_back(f+1);
		edge[f+1].push_back(i);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		string op;
		int x;
		cin>>op>>x;
		if(op=="install")
			printf("%d\n",path(x+1,1));
		else
		{
			printf("%d\n",query(1,id[x+1],id[x+1]+size[x+1]-1));
			update(1,id[x+1],id[x+1]+size[x+1]-1,0);
		}
	}
	return 0;
}