#include<bits/stdc++.h>
using namespace std;
stack<int> s;
double n,sum,flag;
vector<int> edge[300001],edge2[300001];
int m,tot,cnt,dfn[100001],low[100001],vis[100001],color[100001],p[100001],in[100001];
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	s.push(u);
	vis[u]=1;
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
	if(low[u]==dfn[u])
	{
		int x;
		cnt++;
		do
		{
			x=s.top();
			s.pop();
			vis[x]=0;
			color[x]=cnt;
			p[cnt]++;
		}
		while(x!=u);
	}
}
int check(int u)
{
	for(int i=0;i<edge2[u].size();i++)
		if(in[edge2[u][i]]==1)
			return 0;
	return 1;
}
int main()
{
	scanf("%lf%d",&n,&m);
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
				in[color[edge[i][j]]]++;
				edge2[color[i]].push_back(color[edge[i][j]]);
			}
	for(int i=1;i<=cnt;i++)
	{
		if(!in[i])
			sum++;
		if(!in[i]&&p[i]==1&&check(i))
			flag=1;
	}
	if(flag)
		sum--;
	printf("%.6lf",1.0-sum/n);
	return 0;
}
