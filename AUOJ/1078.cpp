#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,m,p1,p2,s1,s2,mn,sum1,sum2,c[N];
ll Abs(ll x)
{
	return x>0 ? x : -x;
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	scanf("%lld%lld%lld%lld",&m,&p1,&s1,&s2);
	c[p1]+=s1;
	for(int i=1;i<=m-1;i++)
		sum1+=c[i]*(m-i);
	for(int i=m+1;i<=n;i++)
		sum2+=c[i]*(i-m);
	mn=Abs(sum1-sum2);
	p2=m;
	for(int i=1;i<=m-1;i++)
		if(mn>Abs(sum1+s2*(m-i)-sum2))
		{
			mn=Abs(sum1+s2*(m-i)-sum2);
			p2=i;
		}
	for(int i=m+1;i<=n;i++)
		if(mn>Abs(sum1-sum2-s2*(i-m)))
		{
			mn=Abs(sum1-sum2-s2*(i-m));
			p2=i;
		}
	printf("%lld",p2);
	return 0;
}