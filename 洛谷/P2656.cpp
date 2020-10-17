#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
struct Edge
{
	int v;
	int c;
	double l;
};
vector<Edge> edge[80001];
vector<pii> edge2[80001];
stack<int> st;
queue<int> q;
int n,m,s,tot,cnt,ans,dfn[80001],low[80001],vis[80001],color[80001],p[80001],dis[80001];
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	vis[u]=1;
	st.push(u);
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
			if(vis[v])
				low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int x;
		cnt++;
		do
		{
			x=st.top();
			st.pop();
			vis[x]=0;
			color[x]=cnt;
		}
		while(u!=x);
	}
}
int Cal(int x,double y)
{
	int ans=0;
	while(x)
	{
		ans+=x;
		x=x*y;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		double d;
		scanf("%d%d%d%lf",&a,&b,&c,&d);
		edge[a].push_back(Edge{b,c,d});
	}
	scanf("%d",&s);
	tarjan(s);
	for(int i=1;i<=n;i++)
		for(int j=0;j<edge[i].size();j++)
			if(color[i]==color[edge[i][j].v])
				p[color[i]]+=Cal(edge[i][j].c,edge[i][j].l);
	for(int i=1;i<=n;i++)
		for(int j=0;j<edge[i].size();j++)
			if(color[i]!=color[edge[i][j].v])
				edge2[color[i]].push_back(mp(color[edge[i][j].v],edge[i][j].c+p[color[edge[i][j].v]]));
	q.push(color[s]);
	dis[color[s]]=p[color[s]];
	vis[color[s]]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<edge2[u].size();i++)
		{
			int v=edge2[u][i].first,c=edge2[u][i].second;
			if(dis[v]<dis[u]+c)
			{
				dis[v]=dis[u]+c;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	for(int i=1;i<=cnt;i++)
		ans=max(ans,dis[i]);
	printf("%d",ans);
	return 0;
}
