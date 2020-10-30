#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,dp[500010][510];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=9;i++)
		dp[i][i%m]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m-1;j++)
			for(int k=1;k<=9;k++)
				dp[i+k][(j*10+k)%m]=(dp[i+k][(j*10+k)%m]+dp[i][j])%mod;
	printf("%d",dp[n][0]);
	return 0;
}