#include<cstdio>
#define max(a,b) a>b?a:b
using namespace std;
int m,n,a[501],opt[45001];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=a[i];j--)
			opt[j]=max(opt[j],opt[j-a[i]]+a[i]);
	printf("%d",opt[m]);
	return 0;
}
