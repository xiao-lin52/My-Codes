#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	long long v,c;
};
struct node
{
	long long id,card,dist;
	bool operator<(const node &x)const
    {
        return x.dist<dist;
    }
};
vector<Edge> edge[10010];
priority_queue<node> q;
long long n,m,k,dis[10010][30],b[10010][30];
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		edge[x].push_back(Edge{y,z});
		edge[y].push_back(Edge{x,z});
	}
	dis[1][0]=0;
	q.push(node{1,0,0});
	while(q.size())
	{
		node t=q.top();
		register int u=t.id,d=t.dist,p=t.card;
		q.pop();
		if(d>dis[u][p])
			continue;
		for(int i=0;i<edge[u].size();i++)
		{
			long long v=edge[u][i].v,w=edge[u][i].c;
			if(dis[v][p]>max(dis[u][p],w))
			{
				dis[v][p]=max(dis[u][p],w);
				q.push(node{v,p,dis[v][p]});
			}
			if(dis[v][p+1]>dis[u][p]&&p+1<=k)
			{
				dis[v][p+1]=dis[u][p];
				q.push(node{v,p+1,dis[v][p+1]});
			}
		}
	}
	if(dis[n][k]==dis[0][0])
		printf("-1");
	else
		printf("%lld",dis[n][k]);
	return 0;
}