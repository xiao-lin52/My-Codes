#include<cstdio>
using namespace std;
long long n,m,h,t,a[50001];	
int main()
{
	scanf("%lld%lld",&n,&m);
	h=1;
	t=n;
	for(int i=1;i<=n;i++)
		if((n-i)*(n-i-1)/2>=m)
			a[h++]=i;
		else
		{
			a[t--]=i;
			m=m-(t-(h-1));
		}
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
	return 0;
}
