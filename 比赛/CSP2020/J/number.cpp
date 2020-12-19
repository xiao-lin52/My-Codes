#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll n,m,a[N][N],dp[N][N][3];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(dp,-0x3f,sizeof(dp));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&a[i][j]);
	dp[1][1][0]=dp[1][1][1]=dp[1][1][2]=a[1][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i!=1||j!=1)
			{
				dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1])+a[i][j];
				dp[i][j][1]=max(dp[i][j-1][0],dp[i][j-1][1])+a[i][j];
			}
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
			if(i!=1||j!=1)
			{
				dp[i][j][2]=max(dp[i+1][j][1],dp[i+1][j][2])+a[i][j];
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i!=1||j!=1)
			{
				dp[i][j][1]=max(dp[i][j-1][0],max(dp[i][j-1][1],dp[i][j-1][2]))+a[i][j];
				dp[i][j][0]=max(dp[i][j][0],max(dp[i-1][j][0],dp[i-1][j][1])+a[i][j]);
			}
//	for(int k=0;k<=2;k++)
//	{
//		printf("\n");
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//				printf("%lld ",dp[i][j][k]);
//			printf("\n");
//		}
//	}
	printf("%lld",max(dp[n][m][0],dp[n][m][1]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
