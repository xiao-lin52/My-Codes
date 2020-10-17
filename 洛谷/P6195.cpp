#include<bits/stdc++.h>
#define ll long long
#define p 1000000007
#define x zwc
using namespace std;
ll n,m,t;
inline ll input()
{
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
	{
        if(c=='-')
			f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
	{
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
inline ll ksm(ll b,ll k)
{
	ll ans=1;
	while(k)
	{
		if(k&1)
			ans=ans*b%p;
		b=b*b%p;
		k>>=1;
	}
	return ans%p;
}
int main()
{
 	n=input();
 	m=input();
 	printf("%lld",ksm(2,m)*(n+1)%p-1);
	return 0;
}
