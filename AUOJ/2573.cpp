#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+10;
ll n,ans,dp[N],sum[N];
vector<int> edge[N];
void dfs1(int u,int fa)
{
	sum[u]=1;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa)
		{
			dfs1(v,u);
			if(v<u)
			{
				dp[u]+=sum[v]*(sum[u]-1);
				sum[u]+=sum[v];
			}
		}
	}
}
void dfs2(int u,int fa)
{
	if(fa<u)
	{
		dp[u]+=sum[fa]*(sum[u]-1);
		sum[u]+=sum[fa];
	}
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa)
			dfs2(v,u);
	}
	ans+=dp[u];
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld",ans*2);
	return 0;
}
