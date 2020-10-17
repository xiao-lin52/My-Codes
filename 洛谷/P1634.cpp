#include<cstdio>
using namespace std;
long long n,x,sum=1;
int main()
{
	scanf("%lld%lld",&x,&n);
	for(int i=1;i<=n;i++) sum+=sum*x;
	printf("%lld",sum);
	return 0;
}
