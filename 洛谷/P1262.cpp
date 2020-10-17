#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
vector<int> edge[3001],edge2[3001];
stack<int> st;
int n,p,m,tot,cnt,ans,flag;
int a[3001],dfn[3001],low[3001],vis[3001],color[3001],minn[3001],minp[3001],in[3001],b[3001];
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	vis[u]=1;
	st.push(u);
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
		cnt++;
		do
		{
			x=st.top();
			st.pop();
			vis[x]=0;
			color[x]=cnt;
			minp[cnt]=min(minp[cnt],x);
			if(a[x])
				minn[cnt]=min(minn[cnt],a[x]);
		}
		while(u!=x);
	}
}
void dfs(int u,int q)
{
	if(minn[u]!=inf)
		q=1;
	b[u]=b[u]|q;
	vis[u]=1;
	for(int i=0;i<edge2[u].size();i++)
		if(!vis[edge2[u][i]])
			dfs(edge2[u][i],q);
}
int main()
{
	scanf("%d%d",&n,&p);
	flag=inf;
	memset(minn,inf,sizeof(minn));
	memset(minp,inf,sizeof(minp));
	for(int i=1;i<=p;i++)
	{
		int id,w;
		scanf("%d%d",&id,&w);
		a[id]=w;
	}
	scanf("%d",&m);
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
	for(int i=1;i<=cnt;i++)
		if(!in[i])
			dfs(i,0);
	for(int i=1;i<=cnt;i++)
		if(!b[i])
			flag=min(flag,minp[i]);
		else
			if(!in[i])
				ans+=minn[i];
	if(flag!=inf)
		printf("NO\n%d",flag);
	else
		printf("YES\n%d",ans);
	return 0;
}
