#include<bits/stdc++.h>
#define N 100010
#define mod 1000000007
#define ll long long
using namespace std;
ll n,k,p,dp[N][20],t[N][20],sum[N][20],ans[N][2],mxdep[N];
vector<ll> edge[N];
void pre(int u,int fa,int dep)
{
	mxdep[u]=dep;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa)
		{
			pre(v,u,dep+1);
			mxdep[u]=max(mxdep[u],mxdep[v]);
		}
	}
	mxdep[u]-=dep;
}
void dfs1(int u,int fa)
{
	int flag=1;
	for(int i=0;i<=k&&i<=mxdep[u];i++)
		dp[u][i]=sum[u][i]=1;
	for(int i=0;i<edge[u].size();i++)
	{
		ll v=edge[u][i];
		if(v!=fa)
		{
			dfs1(v,u);
			for(int j=1;j<=k&&j<=mxdep[u];j++)
			{
				sum[u][j]+=sum[v][j-1];
				dp[u][j]=dp[u][j]*dp[v][j-1]%mod;
			}
		}
	}
	for(int i=1;i<=k&&i<=mxdep[u];i++)
		dp[u][i]=dp[u][i]*sum[u][i]%mod;
	for(int i=mxdep[u];i<=k;i++)
	{
		dp[u][i]=dp[u][i-1];
		sum[u][i]=sum[u][i-1];
	}
}
void dfs2(int u,int fa)
{
	if(u==1)
	{
		ans[u][0]=sum[u][k];
		ans[u][1]=dp[u][k];
	}
	else
	{
		ans[u][0]=ans[u][0]+sum[fa][k]-sum[u][k-1];
		ans[u][1]=
	}
	for(int i=0;i<edge[u].size();i++)
	{
		ll v=edge[u][i];
		if(v!=fa)
		{
			dfs2(v,u);
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n-1;i++)
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	pre(1,0,1);
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i][0]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i][1]);
	return 0;
}
