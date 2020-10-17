#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[1000001];
int n,m,s,cnt,log2n,head[500001],dep[500001],fa[500001][21];
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
void dfs(int u,int father)
{
	fa[u][0]=father;
	dep[u]=dep[father]+1;
	for(int i=1;(1<<i)<=dep[u];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next)
		if(edge[i].to!=father)
			dfs(edge[i].to,u);
}
int lca(int u,int v)
{
	int depu=dep[u],depv=dep[v];
	if(depu!=depv)
	{
		if(depu<depv)
		{
			swap(u,v);
			swap(depu,depv);
		}
		for(int i=0;i<=log2n;i++)
			if((1<<i)&(depu-depv))
				u=fa[u][i];
	}
	if(u==v)
		return u;
	for(int i=log2n;i>=0;i--)
		if(fa[u][i]==fa[v][i]||fa[u][i]==0)
			continue;
		else
		{
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	log2n=log(n)/log(2)+0.5;
	dfs(s,0);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}
