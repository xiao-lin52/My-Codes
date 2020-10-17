#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define N 160
#define inf 0x3f3f3f3f
using namespace std;
int n,p,ans,size[N],dp[N][N];
vector<int> edge[N];
void dfs(int u,int fa)
{
	size[u]=1;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa)
		{
			dfs(v,u);
			size[u]+=size[v];
			dp[v][size[v]]=1;
			for(int j=n;j>=1;j--)
				for(int k=1;k<=j;k++)
					dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]);
		}
	}
}
int main()
{
	while(~scanf("%d%d",&n,&p))
	{
		ans=inf;
		memset(size,0,sizeof(size));
		memset(dp,inf,sizeof(dp));
		for(int i=1;i<=n;i++)
			edge[i].clear();
		for(int i=1;i<=n;i++)
			dp[i][0]=0;
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		dfs(1,0);
		ans=dp[1][n-p];
		for(int i=2;i<=n;i++)
			if(size[i]>=p)
				ans=min(ans,dp[i][size[i]-p]+1);
		printf("%d\n",ans);
	}
	return 0;
}
