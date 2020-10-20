#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
struct SegTree
{
	int l;
	int r;
	ll data;
	ll add;
	ll mul;
};
SegTree tree[N<<2];
int n,m;
ll p,a[N];
inline void push_up(int i)
{
	tree[i].data=(tree[i<<1].data+tree[i<<1|1].data)%p;
}
inline void push_down(int i)
{
	int ls=i<<1,rs=i<<1|1;
	tree[ls].data=((tree[ls].data*tree[i].mul%p)+tree[i].add)%p;
	tree[rs].data=((tree[rs].data*tree[i].mul%p)+tree[i].add)%p;
	tree[ls].add=((tree[ls].add*tree[i].mul%p)+tree[i].add)%p;
	tree[rs].add=((tree[rs].add*tree[i].mul%p)+tree[i].add)%p;
	tree[ls].mul=tree[ls].mul*tree[i].mul%p;
	tree[rs].mul=tree[rs].mul*tree[i].mul%p;
	tree[i].add=0;
	tree[i].mul=1;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	tree[i].mul=1;
	if(l==r)
	{
		tree[i].data=a[l]%p;
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
}
void update_mul(int i,int l,int r,ll k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=tree[i].data*k%p;
		tree[i].mul=tree[i].mul*k%p;
		tree[i].add=tree[i].add*k%p;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update_mul(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update_mul(i<<1|1,l,r,k);
	push_up(i);
}
void update_add(int i,int l,int r,ll k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=(tree[i].data+k)%p;
		tree[i].add=(tree[i].add+k)%p;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update_add(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update_add(i<<1|1,l,r,k);
	push_up(i);
}
ll query(int i,int l,int r)
{
	ll sum=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
		sum=(sum+query(i<<1,l,r))%p;
	if(tree[i<<1|1].l<=r)
		sum=(sum+query(i<<1|1,l,r))%p;
	return sum;
}
int main()
{
	scanf("%d%d%lld",&n,&m,&p);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		ll k;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			scanf("%lld",&k);
			update_mul(1,x,y,k);
		}
		if(op==2)
		{
			scanf("%lld",&k);
			update_add(1,x,y,k);
		}
		if(op==3)
			printf("%lld\n",query(1,x,y));
	}
	return 0;
}
