#include<bits/stdc++.h>
using namespace std;
vector<int> edge[10001];
int n,dp[10001][3];
void dfs(int u,int fa)
{
	int flag=0,p=1000000000;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(fa==v)
			continue;
		dfs(v,u);
		dp[u][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
		if(dp[v][1]>dp[v][0])
		{
			flag=1;
			dp[u][1]+=dp[v][0];
		}
		else
		{
			p=min(p,dp[v][0]-dp[v][1]);
			dp[u][1]+=dp[v][1];
		}
		dp[u][2]+=min(dp[v][0],dp[v][1]);
	}
	dp[u][0]+=1;
	if(!flag)
		dp[u][1]+=p;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",min(dp[1][0],dp[1][1]));
	return 0;
}
