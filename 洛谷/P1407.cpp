#include<bits/stdc++.h>
using namespace std;
vector<int> edge[8001];
map<string,int> p;
stack<int> s;
int n,m,k,tot,cnt,dfn[8001],low[8001],vis[8001],num[8001],color[8001],que[20001][3];
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
			num[cnt]++;
			color[x]=cnt;
		}
		while(x!=u);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		if(!p[a])
			p[a]=++k;
		if(!p[b])
			p[b]=++k;
		edge[k-1].push_back(k);
		que[i][1]=p[a];
		que[i][2]=p[b];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		string x,y;
		cin>>x>>y;
		edge[p[y]].push_back(p[x]);
	}
	for(int i=1;i<=k;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(num[color[que[i][1]]]>=2&&num[color[que[i][2]]]>=2)
			printf("Unsafe\n");
		else
			printf("Safe\n");
	return 0;
}
