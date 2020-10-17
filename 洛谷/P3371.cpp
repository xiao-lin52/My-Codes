#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define re register
#define inf 0x3f3f3f3f
using namespace std;
vector<pii> edge[100001];
deque<int> q;
int n,m,s,sum,num,dis[100001],vis[100001];
int main()
{
	memset(dis,inf,sizeof(dis));
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		re int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		edge[x].push_back(mp(y,z));
	}
	dis[s]=0;
	q.push_front(s);
	num++;
	vis[s]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop_front();
		while(num&&dis[u]>sum/num)
		{
			q.push_back(u);
			u=q.front();
			q.pop_front();
		}
		vis[u]=0;
		num--;
		sum-=dis[u];
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first,c=edge[u][i].second;
			if(dis[u]+c<dis[v])
			{
				dis[v]=dis[u]+c;
				if(!vis[v])
				{
					num++;
					sum+=dis[v];
					vis[v]=1;
					if(q.size()&&dis[v]<dis[q.size()])
						q.push_front(v);
					else
						q.push_back(v);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(dis[i]==inf)
			printf("2147483647 ");
		else
			printf("%d ",dis[i]);
	return 0;
}
