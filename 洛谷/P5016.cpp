#include<cstdio>
#define ll long long 
using namespace std;
ll abs_m(ll x){return x>0? x:0-x;}
ll n,m,p1,s1,p2,s2,a1,a2,gap,c[100001];
int main()
{
	scanf("%lld",&n);
	for(int i=1; i<=n; i++)
		scanf("%lld",&c[i]);
	scanf("%lld%lld%lld%lld",&m,&p1,&s1,&s2);
	c[p1]+=s1;
	for(int i=1; i<=n; i++)
	{
		if(i<m)
			a1+=c[i]*(m-i);
		if(i>m)
			a2+=c[i]*(i-m);
	}
	gap=1000000000000;
	for(int i=1; i<=n; i++)
	{
		ll t1=a1,t2=a2;
		if(i<m)
			t1+=s2*(m-i);
		if(i>m)
			t2+=s2*(i-m);
		if(abs_m(t1-t2)<gap)
		{
			p2=i;
			gap=abs_m(t1-t2);
		}
	}
	printf("%lld",p2);
	return 0;
}
