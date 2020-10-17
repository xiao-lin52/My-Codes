#include<cstdio>
#include<algorithm>
using namespace std;
int n,a,b;
long long sum;
int main()
{
	scanf("%d%d",&n,&a);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&b);
		sum+=max(a,b);
		a=b;
	}
	printf("%lld",sum);
	return 0;
}
