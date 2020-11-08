#include<bits/stdc++.h>
#define N 3010
using namespace std;
int n,a[N],b[N],c[N];
long long dp[N][2];
int main()
{
	memset(dp,-0x3f,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dp[1][1]=0;
	for(int i=2;i<=n+1;i++)
	{
		dp[i][0]=max(dp[i-1][0]+b[i-1],dp[i-1][1]+a[i-1]);
		dp[i][1]=max(dp[i-1][0]+c[i-1],dp[i-1][1]+b[i-1]);
	}
	printf("%lld",dp[n+1][0]);
	return 0;
}
