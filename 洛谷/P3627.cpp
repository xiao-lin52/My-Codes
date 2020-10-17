#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define re register int
using namespace std;
inline int input()
{
	re x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
vector<int> edge[500001];
vector<pii> edge2[500001];
stack<int> st;
queue<int> q;
int n,m,s,p,tot,cnt,t,a[500001];
int dfn[500001],low[500001],vis[500001],color[500001],w[500001];
int sum,num,ans,dis[500001];
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	vis[u]=1;
	st.push(u);
	for(re i=0;i<edge[u].size();i++)
	{
		re v=edge[u][i];
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
		re x;
		cnt++;
		do
		{
			x=st.top();
			st.pop();
			vis[x]=0;
			color[x]=cnt;
			w[cnt]+=a[x];
		}
		while(u!=x);
	}
}
int main()
{
	n=input();
	m=input();
	for(re i=1;i<=m;i++)
	{
		re x,y;
		x=input();
		y=input();
		edge[x].push_back(y);
	}
	for(re i=1;i<=n;i++)
		a[i]=input();
	s=input();
	for(re i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(re i=1;i<=n;i++)
		for(re j=0;j<edge[i].size();j++)
			if(color[i]!=color[edge[i][j]])
				edge2[color[i]].push_back(mp(color[edge[i][j]],w[color[edge[i][j]]]));
	q.push(color[s]);
	dis[color[s]]=w[color[s]];
	vis[color[s]]=1;
	while(q.size())
	{
		re u=q.front();
		q.pop();
		vis[u]=0;
		for(re i=0;i<edge2[u].size();i++)
		{
			re v=edge2[u][i].first,c=edge2[u][i].second,k=q.front();
			if(dis[v]<dis[u]+c)
			{
				dis[v]=dis[u]+c;
				q.push(v);
			}
		}
	}
	p=input();
	for(re i=1;i<=p;i++)
	{
		t=input();
		ans=max(ans,dis[color[t]]);
	}
	printf("%d",ans);
	return 0;
}
