#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
struct SegTree
{
	int ls;
	int rs;
	int data;
};
SegTree tree[21*MAXN];
int n,m,tot,qwq,c[MAXN],a[MAXN],root[MAXN];
void build(int &i,int l,int r)
{
	i=++tot;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(tree[i].ls,l,mid);
	build(tree[i].rs,mid+1,r);
}
void update(int &i,int last,int l,int r,int pos)
{
	i=++tot;
	tree[i]=tree[last];
	if(l==r)
	{
		tree[i].data++;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)
		update(tree[i].ls,tree[last].ls,l,mid,pos);
	else
		update(tree[i].rs,tree[last].rs,mid+1,r,pos);
	tree[i].data=tree[tree[i].ls].data+tree[tree[i].rs].data;
}
int query(int i,int his,int l,int r,int k)
{
	if(l==r)
		return l;
	int mid=(l+r)>>1;
	if(tree[tree[i].ls].data-tree[tree[his].ls].data>=k)
		return query(tree[i].ls,tree[his].ls,l,mid,k);
	else
		return query(tree[i].rs,tree[his].rs,mid+1,r,k-tree[tree[i].ls].data+tree[tree[his].ls].data);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(root[0],1,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[++qwq]=a[i];
	}
	sort(c+1,c+1+qwq);
	qwq=unique(c+1,c+1+qwq)-c;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(c+1,c+1+qwq,a[i])-c;
		update(root[i],root[i-1],1,n,a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",c[query(root[r],root[l-1],1,n,k)]);
	}
	return 0;
}