#include<bits/stdc++.h>
using namespace std;
int n,m,fa,w[301],lson[301],rson[301],last[301],dp[301][301];
int dfs(int u,int k)
{
	if(dp[u][k])
		return dp[u][k];
	if(!u)
		return dp[u][k]=0;
	dp[u][k]=dfs(rson[u],k);
	for(int i=0;i<k;i++)
		dp[u][k]=max(dp[u][k],dfs(lson[u],i)+dfs(rson[u],k-i-1)+w[u]);
	return dp[u][k];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&fa,&w[i]);
		if(!last[fa])
			lson[fa]=i;
		else
			rson[last[fa]]=i;
		last[fa]=i;
	}
	printf("%d",dfs(lson[0],m));
	return 0;
}