#include<cstdio>
#define ll long long
using namespace std;
struct node
{
	ll l;
	ll r;
	ll data;
	ll f1;
	ll f2;
};
node tree[400001];
ll n,m,p;
void push_down(ll i)
{
	tree[i*2].data=(tree[i].f1*(tree[i*2].r-tree[i*2].l+1)%p+tree[i].f2*tree[i*2].data%p)%p;
	tree[i*2+1].data=(tree[i].f1*(tree[i*2+1].r-tree[i*2+1].l+1)%p+tree[i].f2*tree[i*2+1].data%p)%p;
	tree[i*2].f1=(tree[i].f1+tree[i*2].f1*tree[i].f2)%p;
	tree[i*2+1].f1=(tree[i].f1+tree[i*2+1].f1*tree[i].f2)%p;
	tree[i*2].f2=tree[i*2].f2*tree[i].f2%p;
	tree[i*2+1].f2=tree[i*2+1].f2*tree[i].f2%p;
	tree[i].f1=0;
	tree[i].f2=1;
}
void build(ll i,ll l,ll r)
{
	tree[i].l=l;
	tree[i].r=r;
	tree[i].f2=1;
	if(l==r)
	{
		scanf("%lld",&tree[i].data);
		tree[i].data%=p;
		return;
	}
	build(i*2,l,(l+r)/2);
	build(i*2+1,(l+r)/2+1,r);
	tree[i].data=(tree[i*2].data+tree[i*2+1].data)%p;
}
void update_mul(ll i,ll l,ll r,ll k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=tree[i].data*k%p;
		tree[i].f2=tree[i].f2*k%p;
		tree[i].f1=tree[i].f1*k%p;
		return;
	}
	push_down(i);
	if(tree[i*2].r>=l)
		update_mul(i*2,l,r,k);
	if(tree[i*2+1].l<=r)
		update_mul(i*2+1,l,r,k);
	tree[i].data=(tree[i*2].data+tree[i*2+1].data)%p;
}
void update_add(ll i,ll l,ll r,ll k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=(tree[i].data+k*(tree[i].r-tree[i].l+1))%p;
		tree[i].f1=(tree[i].f1+k)%p;
		return;
	}
	push_down(i);
	if(tree[i*2].r>=l)
		update_add(i*2,l,r,k);
	if(tree[i*2+1].l<=r)
		update_add(i*2+1,l,r,k);
	tree[i].data=(tree[i*2].data+tree[i*2+1].data)%p;
}
ll query(ll i,ll l,ll r)
{
	ll ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data%p;
	push_down(i);
	if(tree[i*2].r>=l)
		ans=(ans+query(i*2,l,r))%p;
	if(tree[i*2+1].l<=r)
		ans=(ans+query(i*2+1,l,r))%p;
	return ans%p;
}
int main()
{
	scanf("%lld%lld",&n,&p);
	build(1,1,n);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		ll op,l,r,k;
		scanf("%lld%lld%lld",&op,&l,&r);
		switch(op)
		{
			case 1:
				scanf("%lld",&k);
				update_mul(1,l,r,k);
				break;
			case 2:
				scanf("%lld",&k);
				update_add(1,l,r,k);
				break;
			case 3:
				printf("%lld\n",query(1,l,r));
				break;
		}
	}
	return 0;
}