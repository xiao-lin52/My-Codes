#include<bits/stdc++.h>
#define N 3010
using namespace std;
long long n,m,a[N],b[N],c[N],dp[N][N];
int main()
{
	memset(dp,0x3f,sizeof(dp));
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=c[i]=a[i]-i;
	}
	dp[0][1]=0;
	sort(c+1,c+1+n);
	m=unique(c+1,c+1+n)-c-1;
	for(int i=1;i<=m;i++)
		dp[1][i]=min(dp[1][i-1],abs(c[i]-b[1]));
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			dp[i][j]=min(dp[i][j-1],dp[i-1][j]+abs(c[j]-b[i]));
	printf("%lld",dp[n][m]);
	return 0;
}
