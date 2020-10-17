#include<bits/stdc++.h>
#define pii pair<int,int>
#define	mp(a,b) make_pair(a,b)
#define inf 0x3f3f3f3f
using namespace std;
vector<int> edge[200001],edge2[200001];
stack<int> st;
queue<int> q;
int n,m,tot,cnt,k[200001],dfn[200001],low[200001],vis[200001],color[200001],maxn[200001],p[200001];
int res,ans,in[200001],dis[200001],f[200001];
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
			maxn[cnt]=max(maxn[cnt],k[x]);
			p[cnt]+=k[x];
		}
		while(u!=x);
	}
}
int topo()
{
	for(int i=1;i<=cnt;i++)
		if(!in[i])
		{
			dis[i]=p[i];
			f[i]=maxn[i];
			q.push(i);
		}
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<edge2[u].size();i++)
		{
			if(dis[edge2[u][i]]==dis[u]+p[edge2[u][i]])
				f[edge2[u][i]]=max(f[u],f[edge2[u][i]]);
			if(dis[edge2[u][i]]<dis[u]+p[edge2[u][i]])
			{
				dis[edge2[u][i]]=dis[u]+p[edge2[u][i]];
				f[edge2[u][i]]=max(f[u],maxn[edge2[u][i]]);
			}
			in[edge2[u][i]]--;
			if(!in[edge2[u][i]])
				q.push(edge2[u][i]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
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
	topo();
	for(int i=1;i<=cnt;i++)
		if(dis[i]>res)
		{
			res=dis[i];
			ans=f[i];
		}
		else
			if(dis[i]==res)
				ans=max(ans,f[i]);
	printf("%d %d",res,ans);
	return 0;
}
