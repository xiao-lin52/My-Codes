#include<bits/stdc++.h>
using namespace std;
vector<int> edge[1501];
int n,dp[1501][2];
void dfs(int u,int fa)
{
	int flag=0,p=1000000000;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v==fa)
			continue;
		dfs(v,u);
		dp[u][0]+=min(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
	dp[u][0]+=1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k,m,s;
		scanf("%d%d",&k,&m);
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&s);
			edge[k+1].push_back(s+1);
			edge[s+1].push_back(k+1);
		}
	}
	dfs(1,0);
	printf("%d",min(dp[1][0],dp[1][1]));
	return 0;
}