#include<bits/stdc++.h>
using namespace std;
int n,a,dp[101][3];
int main()
{
	scanf("%d",&n);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
		if(a==1||a==3)
			dp[i][1]=min(dp[i-1][1]+1,min(dp[i-1][0],dp[i-1][2]));
		if(a==2||a==3)
			dp[i][2]=min(dp[i-1][2]+1,min(dp[i-1][0],dp[i-1][1]));
	}
	printf("%d",min(dp[n][0],min(dp[n][1],dp[n][2])));
	return 0;
}
