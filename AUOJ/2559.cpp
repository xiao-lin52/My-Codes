#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=1e5+10,inf=1e18;
struct QAQ
{
	ll val;
	ll r;
	int id;
};
bool cmp1(QAQ a,QAQ b){	return a.val>b.val;}
bool cmp2(QAQ a,QAQ b){	return a.id<b.id;}
bool cmp3(QAQ a,QAQ b){	return a.val<b.val;}
QAQ c[N];
ll t,n,m,a,k,sum[N],dp[N],tree[N];
void update(int x,ll k)
{
	for(;x<=n;x+=lowbit(x))
		tree[x]=max(tree[x],k);
}
ll query(int x)
{
	ll ans=-inf;
	for(;x>=1;x-=lowbit(x))
		ans=max(ans,tree[x]);
	return ans;
}
int check(ll k)
{
	memset(tree,-0x3f,sizeof(tree));
	update(sum[0],0);
	for(int i=1;i<=n;i++)
	{
		int t=lower_bound(c,c+1+n,QAQ{})
		dp[i]=query(t)+1;
		if(dp[i]>=m)
			return 1;
		update(sum[i],dp[i]);
	}
	return 0;
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		sum[0]=0;
		c[0]=(QAQ){0,0,0};
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a);
			sum[i]=sum[i-1]+a;
			c[i]=(QAQ){sum[i],0,i};
		}
		sort(c,c+1+n,cmp1);
		c[0].r=1;
		for(int i=1;i<=n;i++)
			if(c[i].val==c[i-1].val)
				c[i].r=c[i-1].r+1;
			else
				c[i].r=c[i-1].r;
		sort(c,c+1+n,cmp2);
		for(int i=0;i<=n;i++)
			sum[i]=c[i].r;
		sort(c,c+1+n,cmp3);
		register ll l=-1e9,r=1e9;
		while(l<r)
		{
			register ll mid=(l+r)>>1;
			if(check(mid))
				r=mid;
			else
				l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}