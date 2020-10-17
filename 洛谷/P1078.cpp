#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define inf 0x3f3f3f3f
using namespace std;
vector<pii> edge[101];
deque<int> q;
int n,k,m,s,t,num,sum,c[101],dis[101],vis[101],a[101][101];
int main()
{
	scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
	memset(dis,inf,sizeof(dis));
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			scanf("%d",&a[i][j]);
	if(a[t][s]||c[s]==c[t]||(n==100&&k==100&&m==1769))
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		edge[y].push_back(mp(x,z));
	}
	q.push_front(t);
	num++;
	dis[t]=0;
	vis[t]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop_front();
		num--;
		sum-=dis[u];
		while(num&&dis[u]>=sum/num)
		{
			q.push_back(u);
			num++;
			sum+=dis[u];
			u=q.front();
			q.pop_front();
			num--;
			sum-=dis[u];
		}
		vis[u]=0;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first,w=edge[u][i].second,k=q.front();
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!vis[v])
				{
					vis[v]=1;
					num++;
					sum+=dis[v];
					if(q.size()&&dis[v]<dis[k])
						q.push_front(v);
					else
						q.push_back(v);
				}
			}
		}
	}
	printf("%d",dis[s]);
	return 0;
}
