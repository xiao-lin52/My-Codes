#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
struct SegTree
{
	ll ls;
	ll rs;
	ll data;
	ll cnt;
};
SegTree tree[N<<4];
ll t,n,m,tot,root,mx,a[N];
void update(ll &i,ll l,ll r,ll x)
{
	if(!i)
		i=++tot;
	if(l==r)
	{
		tree[i].data+=x;
		tree[i].cnt++;
		return;
	}
	ll mid=(l+r)>>1;
	if(mid>=x)
		update(tree[i].ls,l,mid,x);
	else
		update(tree[i].rs,mid+1,r,x);
	tree[i].data=tree[tree[i].ls].data+tree[tree[i].rs].data;
	tree[i].cnt=tree[tree[i].ls].cnt+tree[tree[i].rs].cnt;
}
ll query(ll i,ll l,ll r,ll k)
{
	if(!i)
		return 0;
	ll sum=0;
	if(l==r)
		return min(k/l,tree[i].cnt);
	ll mid=(l+r)>>1;
	if(tree[tree[i].ls].data<=k)
	{
		sum+=tree[tree[i].ls].cnt;
		if(tree[tree[i].rs].data<=k-tree[tree[i].ls].data)
			sum+=tree[tree[i].rs].cnt;
		else
			sum+=query(tree[i].rs,mid+1,r,k-tree[tree[i].ls].data);
	}
	else
		sum+=query(tree[i].ls,l,mid,k);
	return sum;
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		tot=mx=root=0;
		memset(tree,0,sizeof(tree));
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			mx=max(mx,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",i-1-query(root,1,mx,m-a[i]));
			update(root,1,mx,a[i]);
		}
		printf("\n");
	}
	return 0;
}