#include<bits/stdc++.h>
using namespace std;
int  n,m,w[20],sta[300000],dp[300000][2];
int main()
{
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n-1;i++)
		scanf("%d",&w[i]);
	dp[0][0]=dp[0][1]=0;
	for(int i=0;i<=(1<<n)-1;i++)
		for(int j=0;j<=n-1;j++)
			if(!(i&(1<<j)))
				if(dp[i][1]+w[j]<=m)
				{
					if(dp[i|(1<<j)][0]==dp[i][0])
						dp[i|(1<<j)][1]=min(dp[i|(1<<j)][1],dp[i][1]+w[j]);
					else
						if(dp[i|(1<<j)][0]>dp[i][0])
						{
							dp[i|(1<<j)][0]=dp[i][0];
							dp[i|(1<<j)][1]=dp[i][1]+w[j];
						}
				}
				else
				{
					if(dp[i|(1<<j)][0]==dp[i][0]+1)
						dp[i|(1<<j)][1]=min(dp[i|(1<<j)][1],w[j]);
					else
						if(dp[i|(1<<j)][0]>dp[i][0]+1)
						{
							dp[i|(1<<j)][0]=dp[i][0]+1;
							dp[i|(1<<j)][1]=w[j];
						}
				}
	if(dp[(1<<n)-1][1])
		printf("%d",dp[(1<<n)-1][0]+1);
	else
		printf("%d",dp[(1<<n)-1][0]);
	return 0;
}