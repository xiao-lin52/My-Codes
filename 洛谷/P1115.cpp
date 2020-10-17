#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,a[200001],opt[200001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		opt[i]=a[i];
	}
	ans=a[1];
	for(int i=1;i<=n;i++)
	{
		opt[i]=max(a[i],opt[i-1]+a[i]);
		ans=max(ans,opt[i]);
	}
	printf("%d",ans);
	return 0;
}
