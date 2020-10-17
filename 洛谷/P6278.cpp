#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
long long n,maxn,flag,a[100001],tree[100001],sum[100001],ans[100001];
void update(long long x,long long k)
{
	for(;x<=maxn;x+=lowbit(x))
		tree[x]+=k;
}
long long query(long long x)
{
	long long ans=0;
	for(;x;x-=lowbit(x))
		ans+=tree[x];
	return ans;
}
void update_sum(long long x,long long k)
{
	for(;x<=maxn;x+=lowbit(x))
		sum[x]+=k;
}
long long query_sum(long long x)
{
	long long ans=0;
	for(;x;x-=lowbit(x))
		ans+=sum[x];
	return ans;
}
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]++;
		maxn=max(maxn,a[i]);
	}
	for(long long i=1;i<=n;i++)
	{
		update(a[i],1);
		update_sum(a[i],query(maxn)-query(a[i]));
	}
	for(long long i=0;i<=n-1;i++)
		printf("%lld\n",query_sum(i));
	return 0;
}
