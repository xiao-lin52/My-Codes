#include<cstdio>
#define max(a,b) a>b? a:b
#define ll long long
#define N 400010
using namespace std;
struct SegTree
{
	int l;
	int r;
	ll data;
};
SegTree tree[N<<2];
ll n,m,q,mx,sum,a[N];
double st,ed;
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].data=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tree[i].data=max(tree[i<<1].data,tree[i<<1|1].data);
}
void update(int i,int x,int k)
{
	if(tree[i].l>=x&&tree[i].r<=x)
	{
		tree[i].data=k;
		return;
	}
	if(tree[i<<1].r>=x)
		update(i<<1,x,k);
	if(tree[i<<1|1].l<=x)
		update(i<<1|1,x,k);
	tree[i].data=max(tree[i<<1].data,tree[i<<1|1].data);
}
inline ll my_ceil(ll a,ll b)
{
	return a%b ? a/b+1 : a/b;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&q);
	for(register int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	build(1,1,n);
	printf("%lld\n",max(tree[1].data,my_ceil(sum,m)));
	for(register int i=1;i<=q;i++)
	{
		register ll p,c;
		scanf("%lld%lld",&p,&c);
		sum=sum-a[p]+c;
		update(1,p,c);
		printf("%lld\n",max(tree[1].data,my_ceil(sum,m)));
		a[p]=c;
	}
	return 0;
}
