#include<cstdio>
using namespace std;
long long a,b,k,ans=1;
int main()
{
	scanf("%lld%lld%lld",&a,&k,&b);
	while(b)
	{
		if(b&1)
			ans=ans*a%k;
		a=a*a%k;
		b>>=1;
	}
	printf("%lld\n",ans);
}
