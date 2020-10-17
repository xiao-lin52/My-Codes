#include<bits/stdc++.h>
#define N 110
using namespace std;
int n,root,cnt,val[N],dp[N][2];
map<string,int> p;
vector<int> edge[N];
void dfs(int u)
{
	dp[u][1]=val[u];
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		dfs(v);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string u,fa;
		int w;
		cin>>u>>w>>fa;
		if(!p[u])
			p[u]=++cnt;
		val[p[u]]=w;
		if(fa=="NOBODY")
			root=p[u];
		else
		{
			if(!p[fa])
				p[fa]=++cnt;
			edge[p[fa]].push_back(p[u]);
		}
	}
	dfs(root);
	printf("%d",max(dp[root][0],dp[root][1]));
	return 0;
}
