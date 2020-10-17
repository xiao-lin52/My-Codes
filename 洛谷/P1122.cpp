#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
vector<int> edge[16001];
int n,s,ans,w[16001],dp[16001];
void dfs(int u,int fa)
{
	int flag=0;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v==fa)
			continue;
		dfs(v,u);
		dp[u]+=max(dp[v],0);
	}
	dp[u]+=w[u];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		s+=w[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
