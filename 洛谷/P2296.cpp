#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,s,t,vis[N],p[N],dis[N];
vector<int> edge[N],edge1[N];
void dfs(int u)
{
	vis[u]=1;
	for(int i=0;i<edge1[u].size();i++)
		if(!vis[edge1[u][i]])
			dfs(edge1[u][i]);
}
void bfs()
{
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i];
			if(!p[v]&&dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge1[v].push_back(u);
	}
	scanf("%d%d",&s,&t);
	dfs(t);
	for(int i=1;i<=n;i++)
		for(int j=0;j<edge[i].size();j++)
			if(!vis[edge[i][j]])
			{
				p[i]=1;
				break;
			}
	bfs();
	if(dis[t]>1e9)
		printf("-1");
	else
		printf("%d",dis[t]);
	return 0;
}