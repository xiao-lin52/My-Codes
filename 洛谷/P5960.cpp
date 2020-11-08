#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int N=5e3+10;
int n,m,flag,in[N],dis[N],vis[N],cnt[N];
vector<pii> edge[N];
void SPFA(int s)
{
	dis[s]=flag=0;
	queue<int> q;
	q.push(s);
	vis[s]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first,c=edge[u][i].second;
			if(dis[v]>dis[u]+c)
			{
				dis[v]=dis[u]+c;
				if(!vis[v])
				{
					cnt[v]++;
					if(cnt[v]>n)
					{
						flag=1;
						return;
					}
					q.push(v);
					vis[v]=1;
				}
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
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		edge[v].push_back(mp(u,c));
	}
	for(int i=1;i<=n;i++)
		edge[0].push_back(mp(i,0));
	SPFA(0);
	if(flag)
	{
		printf("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
}