#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N=400+10;
int n,m,s,t,k,dis[N],vis[N],ans[N*N];
vector<pii> edge[N];
queue<int> q;
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(mp(v,i));
		edge[v].push_back(mp(u,i));
	}
	q.push(s);
	dis[s]=1;
	vis[s]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first,id=edge[u][i].second;
			if(!ans[id])
				if(vis[t])
					ans[id]=dis[t]-1;
				else
					ans[id]=dis[u];
			if(!vis[v])
			{
				dis[v]=dis[u]+1;
				vis[v]=1;
				q.push(v);
			}
		}
	}
	printf("%d",dis[t]-1);
	for(int i=1;i<=m;i++)
		printf("\n%d",ans[i]);
	return 0;
}