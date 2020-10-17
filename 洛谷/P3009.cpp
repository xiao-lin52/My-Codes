#include<cstdio>
using namespace std;
int n,a,ans=-1000,opt[100001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(opt[i-1]+a<=a)
			opt[i]=a;
		else
			opt[i]=opt[i-1]+a;
		ans=ans>opt[i]?ans:opt[i];
	}
	printf("%d",ans);
	return 0;
}
