#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
struct SegTree
{
	int lson;
	int rson;
	int data;
};
SegTree tree[MAXN*21];
int n,m,tot,root[MAXN];
void build(int &i,int l,int r)
{
	i=++tot;
	if(l==r)
	{
		scanf("%d",&tree[i].data);
		return;
	}
	int mid=(l+r)>>1;
	build(tree[i].lson,l,mid);
	build(tree[i].rson,mid+1,r);
}
void update(int &i,int last,int x,int l,int r,int k)
{
	i=++tot;
	tree[i]=tree[last];
	if(l==r)
	{
		tree[i].data=k;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x)
		update(tree[i].lson,tree[last].lson,x,l,mid,k);
	else
		update(tree[i].rson,tree[last].rson,x,mid+1,r,k);
}
int query(int i,int x,int l,int r)
{
	if(l==r)
		return tree[i].data;
	int mid=(l+r)>>1;
	if(mid>=x)
		return query(tree[i].lson,x,l,mid);
	else
		return query(tree[i].rson,x,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(root[0],1,n);
	for(int i=1;i<=m;i++)
	{
		int ver,op,loc,val;
		scanf("%d%d%d",&ver,&op,&loc);
		if(op==1)
		{
			scanf("%d",&val);
			update(root[i],root[ver],loc,1,n,val);
		}
		else
		{
			printf("%d\n",query(root[ver],loc,1,n));
			root[i]=root[ver];
		}
	}
	return 0;
}