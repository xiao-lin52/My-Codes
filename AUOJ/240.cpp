#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int n,k,m,w[110],dp[110][210];
vector<pii> edge[110];
int dfs(int u,int lst,int fa)
{
	if(dp[u][lst])
		return dp[u][lst];
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i].first,c=edge[u][i].second;
		if(v!=fa)
		{
			for(int j=2*c;j<=lst;j++)
				dp[u][j]=max(dp[u][j],dfs(v,lst-j,u)+w[v]);
		}
	}
	return dp[u][lst];
}
int main()
{
	while(cin>>n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			edge[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		for(int i=1;i<=n-1;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			edge[x].push_back(mp(y,z));
			edge[y].push_back(mp(x,z));
		}
		scanf("%d%d",&k,&m);
		printf("%d\n",dfs(k,m,0)+w[k]);
	}
	return 0;
}
