#include<bits/stdc++.h>
#define N 100010
#define M 500010
using namespace std;
int n,m,cnt,k,ans,u[M],v[M],p[M],val[N],vis[N],dfn[N],low[N],color[N],mx[N],mn[N],maxn[N],minn[N];
vector<int> edge[N],edge2[N];
stack<int> st;
queue<int> q;
void tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
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
		k++;
		do
		{
			x=st.top();
			color[x]=k;
			mx[k]=max(mx[k],val[x]);
			mn[k]=min(mn[k],val[x]);
			vis[x]=0;
			st.pop();
		}
		while(x!=u);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(mn,0x3f,sizeof(mn));
	memset(minn,0x3f,sizeof(minn));
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&p[i]);
		edge[u[i]].push_back(v[i]);
		if(p[i]==2)
			edge[v[i]].push_back(u[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		edge[i].clear();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
		if(color[u[i]]!=color[v[i]])
		{
			edge[color[u[i]]].push_back(color[v[i]]);
			edge2[color[v[i]]].push_back(color[u[i]]);
		}
	memset(vis,0,sizeof(vis));
	q.push(color[1]);
	minn[color[1]]=mn[color[1]];
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<edge[u].size();i++)
			if(minn[edge[u][i]]>min(minn[u],mn[edge[u][i]]))
			{
				minn[edge[u][i]]=min(minn[u],mn[edge[u][i]]);
				if(!vis[edge[u][i]])
				{
					vis[edge[u][i]]=1;
					q.push(edge[u][i]);
				}
			}
	}
	q.push(color[n]);
	maxn[color[n]]=mx[color[n]];
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<edge2[u].size();i++)
			if(maxn[edge2[u][i]]<max(maxn[u],mx[edge2[u][i]]))
			{
				maxn[edge2[u][i]]=max(maxn[u],mx[edge2[u][i]]);
				if(!vis[edge2[u][i]])
				{
					vis[edge2[u][i]]=1;
					q.push(edge2[u][i]);
				}
			}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,maxn[i]-minn[i]);
	printf("%d",ans);
	return 0;
}
