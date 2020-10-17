#include<bits/stdc++.h>
using namespace std;
vector<int> edge[1501];
int n,m,k,s,fa[1501],w[1501],dp[1501][3];
void dfs(int u)
{
	int p=100000000,flag=0;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		dfs(v);
		dp[u][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
		if(dp[v][1]<dp[v][0])
		{
			p=min(p,dp[v][0]-dp[v][1]);
			dp[u][1]+=dp[v][1];
		}
		else
		{
			flag=1;
			dp[u][1]+=dp[v][0];
		}
		dp[u][2]+=min(dp[v][0],dp[v][1]);
	}
	dp[u][0]+=w[u];
	if(!flag)
		dp[u][1]+=p;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		scanf("%d%d",&w[k],&m);
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&s);
			fa[s]=k;
			edge[k].push_back(s);
		}
	}
	for(int i=1;i<=n;i++)
		if(!fa[i])
		{
			dfs(i);
			printf("%d",min(dp[i][0],dp[i][1]));
			break;
		}
	return 0;
}
