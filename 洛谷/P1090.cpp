#include<cstdio>
#include<algorithm>
using namespace std;
long long n,ans,a[100100];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		a[i]=a[i]+a[i+1];
		int t=a[i];
		ans+=t;
		int j;
//		for(j=2;j<n;i++)
//			a[j]=a[j+1];
//		n--;
		for(j=i+1;j<n;j++)
		{
			a[j]=a[j+1];
			if(a[j]>t)
			{
				a[j]=t;
				break;
			}
		}
		if(j==n) a[n]=t;
	}
	printf("%lld",ans);
	return 0;
}
