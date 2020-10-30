#include<bits/stdc++.h>
using namespace std;
long long t,n,m,a[110][110],dp[10010];
int main()
{
	scanf("%lld%lld%lld",&t,&n,&m);
	for(int i=1;i<=t;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	for(int i=1;i<=t-1;i++)
	{
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;j++)
			for(int k=a[i][j];k<=m;k++)
				dp[k]=max(dp[k],dp[k-a[i][j]]+a[i+1][j]-a[i][j]);
		m=max(m,dp[m]+m);
	}
	printf("%lld",m);
	return 0;
}