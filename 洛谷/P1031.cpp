#include<cstdio>
using namespace std;
int n,ans,sum,a[101];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sum/=n;
	for(int i=1;i<=n;i++)
		a[i]-=sum;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=0)
		{
			a[i+1]+=a[i];
			a[i]=0;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
