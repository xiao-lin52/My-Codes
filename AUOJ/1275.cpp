#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int t,n,m,flag,col[N],dp[N][N],cnt[N][3],a[N][N];
void dfs(int u,int p)
{
	if(flag)
		return;
	if(col[u])
	{
		if(col[u]!=p)
			flag=1;
		return;
	}
	col[u]=p;
	cnt[m][p]++;
	for(int v=1;v<=n;v++)
		if(!a[u][v]||!a[v][u])
			dfs(v,p==1 ? 2 : 1);
}
int main()
{
	freopen("team.in","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		flag=m=0;
		memset(dp,0,sizeof(dp));
		memset(col,0,sizeof(col));
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
			if(!col[i])
			{
				m++;
				dfs(i,1);
			}
		if(flag||n==1)
		{
			printf("No solution\n");
			continue;
		}
		dp[0][0]=1;
		for(int i=1;i<=m;i++)
			for(int j=n/2;j>=cnt[i][1]||j>=cnt[i][2];j--)
			{
				if(j>=cnt[i][1])
					dp[i][j]|=dp[i-1][j-cnt[i][1]];
				if(j>=cnt[i][2])
					dp[i][j]|=dp[i-1][j-cnt[i][2]];
			}
		for(int i=n/2;i>=0;i--)
			if(dp[m][i])
			{
				printf("%d\n",n-2*i);
				break;
			}
	}
	return 0;
}