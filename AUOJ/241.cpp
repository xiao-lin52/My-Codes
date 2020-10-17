#include<bits/stdc++.h>
#define N 10010
#define inf 100000000
using namespace std;
int t,n,dp[N][3];
vector<int> edge[N];
void dfs(int u,int fa)
{
	int tmp=0;
	dp[u][1]=1;
	dp[u][0]=inf;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa)
		{
			dfs(v,u);
			dp[u][1]+=min(dp[v][1],dp[v][2]);
			dp[u][2]+=dp[v][0];
		}
	}
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa)
			dp[u][0]=min(dp[u][0],dp[u][2]-dp[v][0]+dp[v][1]);
	}
}
int main()
{
	while(scanf("%d",&n)&&n!=-1)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		dfs(1,0);
		printf("%d\n",min(dp[1][0],dp[1][1]));
		for(int i=1;i<=n;i++)
			edge[i].clear();
	}
	return 0;
}
