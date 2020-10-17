#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int to,c;
};
struct node
{
	int id,p;
};
deque<node> q;
vector<Edge> edge[10010];
int n,m,k,s,t,sum,num,ans=0x3f3f3f3f,b[10010][20],dis[10010][20];
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		edge[x].push_back(Edge{y,z});
		edge[y].push_back(Edge{x,z});
	}
	q.push_back(node{s,0});
	b[s][0]=1;
	dis[s][0]=0;
	sum=0;
	num=1;
	while(q.size())
	{
		while(dis[q.front().id][q.front().p]>sum/num)
		{
			q.push_back(q.front());
			q.pop_front();
		}
		int u=q.front().id,card=q.front().p;
		q.pop_front();
		sum-=dis[u][card];
		num--;
		b[u][card]=0;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].to,w=edge[u][i].c;
			if(dis[v][card]>dis[u][card]+w)
			{
				dis[v][card]=dis[u][card]+w;
				if(!b[v][card])
				{
					b[v][card]=1;
					sum+=dis[v][card];
					num++;
					if(dis[v][card]<dis[q.front().id][q.front().p])
						q.push_front(node{v,card});
					else
						q.push_back(node{v,card});
				}
			}
			if(dis[v][card+1]>dis[u][card]&&card<k)
			{
				dis[v][card+1]=dis[u][card];
				if(!b[v][card+1])
				{
					b[v][card+1]=1;
					sum+=dis[v][card+1];
					num++;
					if(dis[v][card+1]<dis[q.front().id][q.front().p])
						q.push_front(node{v,card+1});
					else
						q.push_back(node{v,card+1});
				}
			}
		}
	}
	for(int i=0;i<=k;i++)
		ans=min(ans,dis[t][i]);
	printf("%d",ans);
	return 0;
}
