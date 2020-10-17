#include<bits/stdc++.h>
using namespace std;
vector<int> edge[5001];
stack<int> st;
int n,m,tot,maxn,dfn[5001],low[5001],vis[5001],temp[5001],ans[5001];
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
		int x,s=0;
		do
		{
			x=st.top();
			st.pop();
			temp[++s]=x;
			vis[x]=0;
		}
		while(u!=x);
		if(s>maxn)
		{
			maxn=s;
			for(int i=1;i<=s;i++)
				ans[i]=temp[i];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,p;
		scanf("%d%d%d",&u,&v,&p);
		if(p==1)
			edge[u].push_back(v);
		else
		{
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	sort(ans+1,ans+1+maxn);
	printf("%d\n",maxn);
	for(int i=1;i<=maxn;i++)
		printf("%d ",ans[i]);
	return 0;
}
