#include<bits/stdc++.h>
using namespace std;
vector<int> edge[101];
int n,k,top,st[101],w[101],fa[101],dep[101],dp[101][101][51][2];
void dfs(int u)
{
	st[++top]=u;
	dep[u]+=dep[fa[u]];
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		dfs(v);
		for(int j=1;j<=top;j++)
		{
			for(int l=k;l>=0;l--)
			{
				dp[u][st[j]][l][0]+=dp[v][st[j]][0][0];
				dp[u][st[j]][l][1]+=dp[v][u][0][0];
				for(int t=0;t<=l;t++)
				{
					dp[u][st[j]][l][0]=min(dp[u][st[j]][l][0],dp[u][st[j]][l-t][0]+dp[v][st[j]][t][0]);
					dp[u][st[j]][l][1]=min(dp[u][st[j]][l][1],dp[u][st[j]][l-t][1]+dp[v][u][t][0]);
				}
			}
		}
	}
	for(int i=1;i<=top;i++)
	{
		dp[u][st[i]][0][0]+=w[u]*(dep[u]-dep[st[i]]);
		for(int j=1;j<=k;j++)
			dp[u][st[i]][j][0]=min(dp[u][st[i]][j][0]+w[u]*(dep[u]-dep[st[i]]),dp[u][st[i]][j-1][1]);
	}
	top--;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&w[i],&fa[i],&dep[i]);
		edge[fa[i]].push_back(i);
	}
	dfs(0);
	printf("%d",dp[0][0][k][0]);
	return 0;
}
