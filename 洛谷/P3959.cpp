#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,mn=inf,ans=inf,a[20][20],dep[20],dp[5000][20][20];
void dfs(int sta,int sum,int num)
{
	if(sta==(1<<n)-1)
	{
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<=n-1;i++)
		if(sta&(1<<i))
			for(int j=0;j<=n-1;j++)
				if(!(sta&(1<<j))&&a[i][j]!=inf)
				{
					if(dp[sta|(1<<j)][j][dep[i]+1]<=sum+dep[i]*a[i][j])
						continue;
					dp[sta|(1<<j)][j][dep[i]+1]=sum+dep[i]*a[i][j];
					dep[j]=dep[i]+1;
					if(sum+dep[i]*mn<ans)
						dfs(sta|(1<<j),sum+dep[i]*a[i][j],num+1);
				}
}
int main()
{
	memset(a,inf,sizeof(a));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		a[u-1][v-1]=a[v-1][u-1]=min(a[u-1][v-1],c);
		mn=min(mn,c);
	}
	for(int i=0;i<=n-1;i++)
	{
		memset(dep,0,sizeof(dep));
		memset(dp,inf,sizeof(dp));
		dep[i]=1;
		dfs(1<<i,0,1);
	}
	printf("%d",ans);
	return 0;
}