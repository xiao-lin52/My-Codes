#include<bits/stdc++.h>
#define mod 100000000
using namespace std;
int n,m,ans,a[20],sta[20][5000],dp[20][5000];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=0;j<=n-1;j++)
		{
			int x;
			scanf("%d",&x);
			a[i]|=x<<j;
		}
	for(int i=1;i<=m;i++)
		for(int j=0;j<=(1<<n)-1;j++)
		{
			if(!(j&(j<<1))&&(a[i]&j)==j)
				sta[i][j]=1;
		}
	for(int j=0;j<=(1<<n)-1;j++)
		if(sta[1][j])
			dp[1][j]=1;
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<=(1<<n)-1;j++)
		{
			if(sta[i][j])
			{
				for(int k=0;k<=(1<<n)-1;k++)
				{
					if(sta[i-1][k]&&!(j&k))
						dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
				}
			}
		}
	}
	for(int i=0;i<=(1<<n)-1;i++)
		ans=(ans+dp[m][i])%mod;
	printf("%d",ans);
	return 0;
}