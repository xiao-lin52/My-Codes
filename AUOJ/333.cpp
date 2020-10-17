#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define N 10010
using namespace std;
int n,p1,p2,dis[N];
vector<pii> edge[N];
void dfs(int u,int fa,int cost)
{
	dis[u]=max(dis[u],cost);
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i].first,w=edge[u][i].second;
		if(v!=fa)
			dfs(v,u,cost+w);
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		p1=p2=0;
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=n;i++)
			edge[i].clear();
		for(int u=2;u<=n;u++)
		{
			int v,c;
			scanf("%d%d",&v,&c);
			edge[u].push_back(mp(v,c));
			edge[v].push_back(mp(u,c));
		}
		dfs(1,0,0);
		for(int i=1;i<=n;i++)
			p1=dis[i]>dis[p1]? i:p1;
		memset(dis,0,sizeof(dis));
		dfs(p1,0,0);
		for(int i=1;i<=n;i++)
			p2=dis[i]>dis[p2]? i:p2;
		dfs(p2,0,0);
		for(int i=1;i<=n;i++)
			printf("%d\n",dis[i]);
	}
	
	return 0;
}
