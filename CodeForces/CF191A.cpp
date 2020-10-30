#include<bits/stdc++.h>
using namespace std;
int n,ans,dp[27][27];
string a[500001];
int main()
{
	cin>>n;
	memset(dp,-0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int l=a[i].length(),s=a[i][0]-'a',e=a[i][a[i].length()-1]-'a';
		for(int j=0;j<=25;j++)
			dp[j][e]=max(dp[j][e],dp[j][s]+l);
		dp[s][e]=max(dp[s][e],l);
	}
	for(int i=0;i<=25;i++)
		ans=max(ans,dp[i][i]);
	printf("%d",ans);
	return 0;
}
