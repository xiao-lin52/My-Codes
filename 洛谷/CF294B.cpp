#include<bits/stdc++.h>
using namespace std;
int n,m,ans,t[101],w[101],dp[201];
int main()
{
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&w[i]);
		m+=t[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=m;j>=t[i];j--)
			dp[j]=min(dp[j],dp[j-t[i]]+w[i]);
	for(int i=m;i>=0;i--)
		if(m-i>=dp[i])
		{
			printf("%d",m-i);
			break;
		}
	return 0;
}
