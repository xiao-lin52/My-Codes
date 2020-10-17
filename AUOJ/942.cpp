#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 500010
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll gcd(ll x,ll y)
{
	if(x<y)
		swap(x,y);
	return y==0? x:gcd(y,x%y);
}
ll n,ans,a[N];
void dfs(ll x,ll step,ll g)
{
	ans=(ans+g*step%mod)%mod;
	for(int i=x+1;i<=n;i++)
	{
		ll t=gcd(g,a[i]);
		if(t>1)
			dfs(i,step+1,t);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(n<=10)
	{
		for(int i=1;i<=n;i++)
			dfs(i,1,a[i]);
		printf("%lld",ans);
	}
	else
	{
		for(int i=1;i<=n;i++)
			ans=(ans+a[i])%mod;
		printf("%lld",ans);
	}
	return 0;
}
