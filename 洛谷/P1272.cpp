#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
vector<int> edge[151];
int n,p,ans,root,fa[151],out[151],dp[151][151];
int dfs(int u)
{
	int size=1;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i],t=0;
		t=dfs(v);
		size+=t;
		for(int j=size;j>=1;j--)
			for(int k=1;k<=j-1;k++)
				dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]-1);
	}
	return size;
}
int main()
{
	scanf("%d%d",&n,&p);
	memset(dp,inf,sizeof(dp));
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		fa[v]=u;
		edge[u].push_back(v);
		out[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=out[i];
		if(!fa[i])
			root=i;
	}
	dfs(root);
	ans=dp[root][p];
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[i][p]+1);
	printf("%d",ans);
	return 0;
}
