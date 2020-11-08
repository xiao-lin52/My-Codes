#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	int r;
	int data;
	int f;
};
node tree[800001];
vector<int> edge[200001];
int n,m,cnt,w[200001],p[200001],b[200001],maxn[200001];
void dfs(int u,int father)
{
	p[u]=++cnt;
	b[cnt]=u;
	for(int i=0;i<edge[u].size();i++)
		dfs(edge[u][i],u);
	maxn[u]=cnt;
}
void push_down(int i)
{
	int l=i<<1,r=i<<1|1;
	if(!tree[i].f)
		return;
	tree[l].f^=1;
	tree[r].f^=1;
	tree[l].data=(tree[l].r-tree[l].l+1)-tree[l].data;
	tree[r].data=(tree[r].r-tree[r].l+1)-tree[r].data;
	tree[i].f=0;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].data=w[b[l]];
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	tree[i].data=tree[i<<1].data+tree[i<<1|1].data;
}
void update(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=(tree[i].r-tree[i].l+1)-tree[i].data;
		tree[i].f^=1;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r);
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
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int a;
		scanf("%d",&a);
		edge[a].push_back(i+1);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	dfs(1,0);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		string op;
		int x;
		cin>>op>>x;
		if(op=="get")
			printf("%d\n",query(1,p[x],maxn[x]));
		else
			update(1,p[x],maxn[x]);
	}
	return 0;
}
