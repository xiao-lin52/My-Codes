#include<cstdio>
#define ll long long
using namespace std;
ll b,p,k,ans=1;
int main()
{
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=",b,p,k);
	while(p>0)
	{
		if(p%2==1)
			ans=ans*b%k;
		b=b*b%k;
		p/=2;
	}
	printf("%lld",ans%k);
	return 0;
}
