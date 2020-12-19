#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10,mod=1e9+7;
ll ans=1,t,n,a,b,f[N];
int main()
{
	scanf("%lld",&n);
	f[0]=f[1]=1;
	for(ll i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2]*(i-1)%mod)%mod;
	for(ll i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		if(x==1)
			a++;
		else
			b++;
	}
	for(ll i=n;i>=n-b+1;i--)
		ans=(ans*i)%mod;
	printf("%lld\n",ans*f[a]%mod);
	return 0;
}