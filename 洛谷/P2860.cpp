#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
stack<int> s;
vector<pii> edge[5001];
int n,m,tot,ans,cnt,in[5001],dfn[5001],low[5001],vis[5001],color[5001];
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++tot;
	s.push(u);
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i].first;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])
				edge[u][i].second=1;
		}
		else
			if(v!=fa)
				low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int x;
		cnt++;
		do
		{
			x=s.top();
			s.pop();
			color[x]=cnt;
		}
		while(x!=u);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge[x].push_back(mp(y,0));
		edge[y].push_back(mp(x,0));
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++)
		for(int j=0;j<edge[i].size();j++)
			if(edge[i][j].second)
			{
				in[color[i]]++;
				in[color[edge[i][j].first]]++;
			}
	for(int i=1;i<=cnt;i++)
		if(in[i]==1)
			ans++;
	printf("%d",(ans+1)/2);
	return 0;
}
