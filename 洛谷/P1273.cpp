#include<bits/stdc++.h>
#define N 3010
using namespace std;
struct Edge
{
	int to;
	int val;
};
int n,m,w[N],mx[N],dp[N][N];
vector<Edge> edge[N];
void dfs(int u)
{
	if(w[u])
	{
		mx[u]=1;
		dp[u][1]=w[u];
		return;
	}
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i].to,c=edge[u][i].val;
		dfs(v);
		mx[u]+=mx[v];
		for(int j=mx[u];j>=1;j--)
			for(int k=0;k<=j;k++)
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]-c);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[i][0]=0;
	for(int i=1;i<=n-m;i++)
	{
		int s;
		scanf("%d",&s);
		for(int j=1;j<=s;j++)
		{
			int y,z;
			scanf("%d%d",&y,&z);
			edge[i].push_back(Edge{y,z});
		}
	}
	for(int i=n-m+1;i<=n;i++)
		scanf("%d",&w[i]);
	dfs(1);
	for(int i=m;i>=1;i--)
		if(dp[1][i]>=0)
		{
			printf("%d",i);
			break;
		}
	return 0;
}
