#include<bits/stdc++.h>
#define ll int
#define N 100010
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll t,n,c1,c2,weight[N],size[N],son[N];
vector<ll> edge[N];
inline void dfs(int u,int fa)
{
	weight[u]=1;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa)
		{
			dfs(v,u);
			if(weight[v]>size[u])
			{
				size[u]=weight[v];
				son[u]=v;
			}
			weight[u]+=weight[v];
		}
	}
	if(n-weight[u]>size[u])
	{
		size[u]=n-weight[u];
		son[u]=fa;
	}
	if(size[u]==size[c1])
		c2=u;
	if(size[u]<size[c1]||!c1)
	{
		c1=u;
		c2=0;
	}
}
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		c1=c2=0;
		memset(weight,0,sizeof(weight));
		memset(size,0,sizeof(size));
		memset(son,0,sizeof(son));
		for(int i=1;i<=n;i++)
			edge[i].clear();
		for(int i=1;i<=n-1;i++)
		{
			ll u=read(),v=read();
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1,0);//
		if(c2)
		{
			for(int i=0;i<edge[c1].size();i++)
				if(edge[c1][i]!=son[c1])
				{
					printf("%d %d\n%d %d\n",c1,edge[c1][i],son[c1],edge[c1][i]);//
					break;
				}
		}
		else
			printf("%d %d\n%d %d\n",c1,son[c1],c1,son[c1]);//
	}
	return 0;
}
