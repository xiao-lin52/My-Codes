#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10,inf=0x3f3f3f3f3f3f3f3f;
ll n,m,a[N],pre[N],dp[N];
stack<ll> mn,mx;
struct SegTree
{
	int l;
	int r;
	ll f;
	ll data;
};
SegTree tree[N<<2];
inline void push_down(int i)
{
	if(!tree[i].f)
		return;
	tree[i<<1].data+=tree[i].f;
	tree[i<<1|1].data+=tree[i].f;
	tree[i<<1].f+=tree[i].f;
	tree[i<<1|1].f+=tree[i].f;
	tree[i].f=0;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	// tree[i].data=inf;
	if(l==r)
	{
		if(l==0)
			tree[i].data=0;
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
}
void update(int i,int l,int r,ll k)
{
	if(l>r)
		return;
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data+=k;
		tree[i].f+=k;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k);
	tree[i].data=min(tree[i<<1].data,tree[i<<1|1].data);
}
ll query(int i,int l,int r)
{
	if(l>r)
		return inf;
	ll ans=inf;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans=min(ans,query(i<<1,l,r));
	if(tree[i<<1|1].l<=r)
		ans=min(ans,query(i<<1|1,l,r));
	return ans;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	build(1,0,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(mn.size())
			update(1,mn.top(),i-1,-a[i]);
		while(mn.size()&&a[mn.top()]>=a[i])
		{
			int t=mn.top();
			mn.pop();
			if(mn.size())
				update(1,mn.top(),t-1,a[t]-a[i]);
			else
				update(1,0,t-1,a[t]-a[i]);
		}
		mn.push(i);
		if(mx.size())
			update(1,mx.top(),i-1,a[i]);
		while(mx.size()&&a[mx.top()]<=a[i])
		{
			int t=mx.top();
			mx.pop();
			if(mx.size())
				update(1,mx.top(),t-1,a[i]-a[t]);
			else
				update(1,0,t-1,a[i]-a[t]);
		}
		mx.push(i);
		int t=lower_bound(pre,pre+1+i,pre[i]-m)-pre;
		dp[i]=query(1,t,i-1)+pre[n];
		update(1,i,i,dp[i]-pre[i]);
	}
	printf("%lld",dp[n]);
	return 0;
}