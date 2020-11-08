#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
long long n,a[100001],dp[100001][2];
string c[100001];
int main()
{
	memset(dp,inf,sizeof(dp));
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	getchar();
	for(int i=1;i<=n;i++)
		getline(cin,c[i]);
	dp[1][1]=a[1];
	dp[1][0]=0;
	for(int i=2;i<=n;i++)
	{
		string q=c[i-1],p=c[i];
		reverse(q.begin(),q.end());
		reverse(p.begin(),p.end());
		if(c[i-1]<=c[i])
			dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if(c[i-1]<=p)
			dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
		if(q<=c[i])
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if(q<=p)
			dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
		if(dp[i][0]==inf&&dp[i][1]==inf)
		{
			printf("-1");
			return 0;
		}
	}
	printf("%lld",min(dp[n][0],dp[n][1]));
	return 0;
}
