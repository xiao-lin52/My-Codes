#include<bits/stdc++.h>
#define ll long long
#define N 1010
#define mod 998244353
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
inline ll ksm(ll b,ll k)
{
	ll sum=1;
	while(k)
	{
		if(k&1)
			sum=sum*b%mod;
		k>>=1;
		b=b*b%mod;
	}
	return sum%mod;
}
ll n,m,x,a[N];
int main()
{
	n=read();
	for(ll i=0;i<=n;i++)
		a[i]=read();
	m=read();
	for(ll i=1;i<=m;i++)
	{
		ll sum=0;
		x=read();
		for(ll j=0;j<=n;j++)
			sum=(sum+a[j]*ksm(x,j))%mod;
		printf("%lld ",sum);
	}
	return 0;
}

