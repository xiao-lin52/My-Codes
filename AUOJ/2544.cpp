#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,s,tot,a,sum[510],dp[510][510];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		sum[i]=sum[i-1]+a;
	}
	for(int step=0;step<=n-1;step++)
		for(int l=1;l<=n-step;l++)
		{
			int r=l+step;
			dp[l][r]=0x3f3f3f3f;
			for(int k=l;k<=r;k++)
				dp[l][r]=min(dp[l][r],max(dp[l][k-1]+sum[r]-sum[k],dp[k+1][r]+sum[k-1]-sum[l-1]));
		}
	printf("%d",dp[1][n]);
	return 0;
}