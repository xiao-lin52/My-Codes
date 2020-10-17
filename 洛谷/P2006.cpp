#include<cstdio>
using namespace std;
long long k,m,n,a,b,p;
int main()
{
	scanf("%lld%lld%lld",&k,&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&a,&b);
		if(a==0)
		{
			printf("%d ",i);
			p=1;
			continue;
		}
		if(k/a*b>=n)
		{
			printf("%d ",i);
			p=1;
		}
	}
	if(!p)
		printf("-1");
	return 0;
}