#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct SegTree
{
	int ls;
	int rs;
	int data;
};
SegTree tree[N*21];
int n,m,tot,qwq,a[N],c[N],rt[N];
inline void push_up(int i)
{
	tree[i].data=tree[tree[i].ls].data+tree[tree[i].rs].data;
}
void update(int i,int &j,int l,int r,int x)
{
	j=++tot;
	tree[j]=tree[i];
	if(l==r)
	{
		tree[j].data++;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
		update(tree[i].ls,tree[j].ls,l,mid,x);
	else
		update(tree[i].rs,tree[j].rs,mid+1,r,x);
	push_up(j);
}
int query(int i,int j,int l,int r,int k)
{
	if(l==r)
		return l;
	int mid=(l+r)>>1;
	if(tree[tree[j].ls].data-tree[tree[i].ls].data>=k)
		return query(tree[i].ls,tree[j].ls,l,mid,k);
	else
		return query(tree[i].rs,tree[j].rs,mid+1,r,k-(tree[tree[j].ls].data-tree[tree[i].ls].data));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[++qwq]=a[i];
	}
	sort(c+1,c+1+n);
	qwq=unique(c+1,c+1+n)-c-1;
	for(int i=1;i<=n;i++)
	{
		update(rt[i-1],rt[i],1,n,lower_bound(c+1,c+1+qwq,a[i])-c);
	}
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",c[query(rt[l-1],rt[r],1,n,k)]);
	}
	return 0;
}