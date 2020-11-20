#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct SegTree
{
	int ls;
	int rs;
	int data;
};
struct Query
{
	int l;
	int r;
	int x;
};
SegTree tree[N*40];
Query q[N];
int n,m,tot,qwq,a[N],c[N<<1],rt[N];
void update(int i,int &j,int l,int r,int x)
{
	j=++tot;
	tree[j]=tree[i];
	tree[j].data++;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(x<=mid)
		update(tree[i].ls,tree[j].ls,l,mid,x);
	else
		update(tree[i].rs,tree[j].rs,mid+1,r,x);
}
int query(int i,int j,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(x==mid)
		return tree[tree[j].ls].data-tree[tree[i].ls].data;
	if(x<mid)
		return query(tree[i].ls,tree[j].ls,l,mid,x);
	if(x>mid)
		return tree[tree[j].ls].data-tree[tree[i].ls].data+query(tree[i].rs,tree[j].rs,mid+1,r,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[++qwq]=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].x);
		q[i].l++;
		q[i].r++;
		c[++qwq]=q[i].x;
	}
	sort(c+1,c+1+qwq);
	qwq=unique(c+1,c+1+qwq)-c-1;
	for(int i=1;i<=n;i++)
		update(rt[i-1],rt[i],1,qwq,lower_bound(c+1,c+1+qwq,a[i])-c);
	for(int i=1;i<=m;i++)
		printf("%d\n",query(rt[q[i].l-1],rt[q[i].r],1,qwq,lower_bound(c+1,c+1+qwq,q[i].x)-c));
	return 0;
}