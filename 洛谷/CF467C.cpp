#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,a[5001],sum[5001],dp[5001][5001];
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=m;i<=n;i++)
		for(int j=1;m*j<=n&&j<=k;j++)
			dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
	printf("%lld",dp[n][k]);
	return 0;
}
