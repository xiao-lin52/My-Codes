#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
string a,b;
int n,m,ans,dp[5001][5001];
int main()
{
	getline(cin,a);
	getline(cin,b);
	n=a.length();
	m=b.length();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i-1]==b[j-1])
				dp[i][j]=(dp[i][j-1]+dp[i-1][j-1]+1)%mod;
			else
				dp[i][j]=dp[i][j-1];
	for(int i=1;i<=n;i++)
		ans=(ans+dp[i][m])%mod;
	printf("%d",ans);
	return 0;
}
