#include<bits/stdc++.h>
using namespace std;
vector<int> edge[6001];
int n,fa[6001],r[6001],dp[6001][2];
void dfs(int u)
{
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		dfs(v);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
	dp[u][1]+=r[u];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&v,&u);
		edge[u].push_back(v);
		fa[v]=u;
	}
	for(int i=1;i<=n;i++)
		if(!fa[i])
		{
			dfs(i);
			printf("%d",max(dp[i][0],dp[i][1]));
			break;
		}
	return 0;
}
