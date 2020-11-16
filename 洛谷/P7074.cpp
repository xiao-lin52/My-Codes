#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+10;
ll n,m,mx,a[N][N],dp[N][N];
int main()
{
	memset(dp,-0x3f,sizeof(dp));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&a[i][j]);
	dp[0][1]=0;
	for(int i=1;i<=n;i++)
		dp[i][1]=a[i][1]+dp[i-1][1];
	for(int j=2;j<=m;j++)
	{
		mx=dp[1][j-1];
		for(int i=1;i<=n;i++)
		{
			mx=max(dp[i][j-1],mx)+a[i][j];
			dp[i][j]=max(dp[i][j],mx);
		}
		mx=dp[n][j-1];
		for(int i=n;i>=1;i--)
		{
			mx=max(dp[i][j-1],mx)+a[i][j];
			dp[i][j]=max(dp[i][j],mx);
		}
	}
	printf("%lld",dp[n][m]);
	return 0;
}