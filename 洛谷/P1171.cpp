#include<bits/stdc++.h>
#define min(a,b) a<b? a:b
using namespace std;
int n,ans,dis[21][21],dp[1100000][21];
int main()
{
	ans=0x3f3f3f3f;
	memset(dp,0x3f,sizeof(dp));
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);
	dp[1][1]=0;
	for(register int j=1;j<=(1<<n)-1;j++)
		for(register int i=1;i<=n;i++)
		{
			if(!(j&(1<<(i-1))))
				continue;
			for(register int k=1;k<=n;k++)
			{
				if(!(j&(1<<(k-1))))
					continue;
				dp[j][k]=min(dp[j][k],dp[j^(1<<(k-1))][i]+dis[i][k]);
			}
		}
	for(register int i=2;i<=n;i++)
		ans=min(ans,dp[(1<<n)-1][i]+dis[i][1]);
	printf("%d",ans);
	return 0;
}