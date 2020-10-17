#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,ans=10000000,ans1,step,left,right,a[210],sum[210],opt[210][210],opt1[210][210];
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		a[i+n]=a[i];
	}
	for(int i=n+1; i<=2*n; i++)
		sum[i]=sum[i-1]+a[i];
	for(step=1; step<n; step++)
		for(left=1; left<=n*2-step; left++)
		{
			right=left+step;
			opt[left][right]=10000000;
			for(k=left; k<right; k++)
			{
				opt[left][right]=min(opt[left][k]+opt[k+1][right]+sum[right]-sum[left-1],opt[left][right]);
				opt1[left][right]=max(opt1[left][k]+opt1[k+1][right]+sum[right]-sum[left-1],opt1[left][right]);
			}
		}
	for(int i=1; i<=n; i++)
	{
		ans=min(ans,opt[i][i+n-1]);
		ans1=max(ans1,opt1[i][i+n-1]);
	}
	printf("%d\n%d",ans,ans1);
	return 0;
}
