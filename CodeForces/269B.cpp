#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[5001],dp[5001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%*lf",&a[i]);
		dp[i]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			if(a[j]<=a[i])
				dp[i]=max(dp[i],dp[j]+1);
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%d",n-ans);
	return 0;
}
