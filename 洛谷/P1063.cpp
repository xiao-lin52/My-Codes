#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,ans,step,left,right,a[210],sum[210],opt[210][210];
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(step=1; step<n; step++)
		for(left=1; left<=n*2-step; left++)
		{
			right=left+step;
			for(k=left; k<right; k++)
				opt[left][right]=max(opt[left][k]+opt[k+1][right]+a[left]*a[k+1]*a[right+1],opt[left][right]);
		}
	for(int i=1; i<=n; i++)
		ans=max(ans,opt[i][i+n-1]);
	printf("%d",ans);
	return 0;
}
