#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
typedef unsigned long long ll;
const ll N=1e6+10;
ll cnt(ll x)
{
	ll sum=0;
	for(;x;x-=lowbit(x))
		sum++;
	return sum;
}
ll n,m,c,k,mk,ans,a[N],p[N],q[N];
bitset<100000010> lt;
int main()
{
	scanf("%llu%llu%llu%llu",&n,&m,&c,&k);
	for(ll i=1;i<=n;i++)
	{
		scanf("%llu",&a[i]);
		mk|=a[i];
	}
	for(ll i=1;i<=m;i++)
	{
		scanf("%llu%llu",&p[i],&q[i]);
		if(mk&(1ull<<p[i]))
			lt[q[i]]=1;
	}
	for(ll i=1;i<=m;i++)
		if(!lt[q[i]]&&!(ans&(1ull<<p[i])))
			ans^=(1ull<<p[i]);
	ll tot=k-cnt(ans);
	if(tot==64)
		if(n==0)
			printf("18446744073709551616");
		else
			printf("%llu",18446744073709551616-n);
	else
		printf("%llu",(1ull<<tot)-n);
	return 0;
}