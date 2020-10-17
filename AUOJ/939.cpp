#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll a,b,t;
ll gcd(ll x,ll y)
{
	if(x<y)
		swap(x,y);
	return y==0? x:gcd(y,x%y);
}
int main()
{
	a=read();
	b=read();
	t=read();
	printf("%lld",t/(1ll*a*b/gcd(a,b)));
	return 0;
}
