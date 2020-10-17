#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
	int l;
	int r;
	int maxn;
	int minn;
};
node tree[200001];
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		int t;
		scanf("%d",&t);
		tree[i].maxn=tree[i].minn=t;
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tree[i].maxn=max(tree[i<<1].maxn,tree[i<<1|1].maxn);
	tree[i].minn=min(tree[i<<1].minn,tree[i<<1|1].minn);
}
int query_min(int i,int l,int r)
{
	int ans=inf;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].minn;
	if(tree[i<<1].r>=l)
		ans=min(ans,query_min(i<<1,l,r));
	if(tree[i<<1|1].l<=r)
		ans=min(ans,query_min(i<<1|1,l,r));
	return ans;
}
int query_max(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].maxn;
	if(tree[i<<1].r>=l)
		ans=max(ans,query_max(i<<1,l,r));
	if(tree[i<<1|1].l<=r)
		ans=max(ans,query_max(i<<1|1,l,r));
	return ans;
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",query_max(1,x,y)-query_min(1,x,y));
	}
	return 0;
}
