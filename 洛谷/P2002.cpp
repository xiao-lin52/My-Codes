#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,tot,ans,dfn[100001],low[100001],vis[100001],color[100001],in[100001];
vector<int> edge[500001],edge2[500001];
stack<int> s;
void tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	vis[u]=1;
	s.push(u);
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
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
		tot++;
		do
		{
			x=s.top();
			s.pop();
			vis[x]=0;
			color[x]=tot;
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
		edge[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=0;j<edge[i].size();j++)
			if(color[i]!=color[edge[i][j]])
			{
				edge2[color[i]].push_back(color[edge[i][j]]);
				in[color[edge[i][j]]]++;
			}
	for(int i=1;i<=tot;i++)
		if(!in[i])
			ans++;
	printf("%d",ans);
	return 0;
}