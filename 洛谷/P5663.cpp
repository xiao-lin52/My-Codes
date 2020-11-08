#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int N=1e5+10;
int n,m,q,in[N],dis[N][2];
vector<int> edge[N];
void bfs()
{
	queue<pii> q;
	q.push(mp(1,0));
	dis[1][0]=0;
	while(q.size())
	{
		int u=q.front().first,p=q.front().second;
		q.pop();
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i];
			if(dis[v][p^1]>dis[u][p]+1)
			{
				dis[v][p^1]=dis[u][p]+1;
				q.push(mp(v,p^1));
			}
		}
	}
}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
		in[u]++;
		in[v]++;
	}
	bfs();
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(dis[x][y&1]>y||!in[1]||!in[x])
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}