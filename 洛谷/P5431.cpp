#include<bits/stdc++.h>
#define ll long long
#define N 5000010
using namespace std;
inline void read(ll &x)
{
	x=0;
	register char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=x*10+(ch^48),ch=getchar();
}
ll n,p,k,ans,sum=1,a[N],s[N],sv[N];
inline ll power(ll b,ll k)
{
	ll ans=1;
	while(k)
	{
		if(k&1)
			ans=ans*b%p;
		b=b*b%p;
		k>>=1;
	}
	return ans;
}
int main()
{
	s[0]=1;
	read(n);
	read(p);
	read(k);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		s[i]=s[i-1]*a[i]%p;
	}
	sv[n]=power(s[n],p-2);
	for(int i=n-1;i>=1;i--)
		sv[i]=sv[i+1]*a[i+1]%p;
	for(int i=1;i<=n;i++)
	{
		sum=sum*k%p;
		ans=(ans+sv[i]*s[i-1]%p*sum%p)%p;
	}
	printf("%lld",ans);
	return 0;
}