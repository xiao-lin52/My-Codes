#include<bits/stdc++.h>
#define inf 1e9
#define mod 1000000007
using namespace std;
int n,m,cnt,ans,f=1,w[100001],dfn[100001],low[100001],vis[100001];
vector<int> edge[100001];
stack<int> s;
void tarjan(int u)
{
	int minn=inf,sum=0;
	dfn[u]=low[u]=++cnt;
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
	if(dfn[u]==low[u])
	{
		int x;
		do
		{
			x=s.top();
			s.pop();
			vis[x]=0;
			if(minn>w[x])
			{
				minn=w[x];
				sum=1;
			}
			else
				if(minn==w[x])
					sum++;
		}
		while(x!=u);
		ans+=minn;
		f=(f*sum)%mod;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
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
	printf("%d %d",ans,f%mod);
	return 0;
}