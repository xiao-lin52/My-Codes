#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,k,ans,t[101],c[101],a[101],dp[100001][2];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=100000;i++)
		dp[i][0]=dp[i][1]=-1e9;
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		a[i]=t[i]-c[i]*k;
	for(int i=1;i<=n;i++)
		if(a[i]>=0)
			for(int j=100000;j>=a[i];j--)
				dp[j][0]=max(dp[j][0],dp[j-a[i]][0]+t[i]);
		else
			for(int j=100000;j>=-a[i];j--)
				dp[j][1]=max(dp[j][1],dp[j+a[i]][1]+t[i]);
	for(int i=0;i<=100000;i++)
		ans=max(ans,dp[i][0]+dp[i][1]);
	if(ans)
		printf("%d",ans);
	else
		printf("-1");
	return 0;
}
