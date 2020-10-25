#include<bits/stdc++.h>
#define mod 19260817
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;
	register char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=(x*10%mod+(ch^48))%mod,ch=getchar();
}
inline int power(int b,int k)
{
	int ans=1;
	while(k)
	{
		if(k&1)
			ans=ans*b%mod;
		b=b*b%mod;
		k>>=1;
	}
}
int p,q,x,y;
void exgcd(int a,int b)
{
	if(!b)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;
	y=t-a/b*x;
}
signed main()
{
	read(p);
	read(q);
	if(!q)
	{
		printf("Angry!");
		return 0;
	}
	exgcd(q,mod);
	x=(x%mod+mod)%mod;
	printf("%lld",p*x%mod);
	return 0;
}