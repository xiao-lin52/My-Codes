#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[200001];
int n,m,a,b,c,d,cnt,log2n,head[100001],dep[100001],fa[100001][21];
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
void dfs(int u,int father)
{
	dep[u]=dep[father]+1;
	fa[u][0]=father;
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
			swap(depu,depv);
			swap(u,v);
		}
		for(int i=0;(1<<i)<=depu-depv;i++)
			if((1<<i)&(depu-depv))
				u=fa[u][i];
	}
	if(u==v)
		return u;
	for(int i=log2n;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
		{
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
int dis(int u,int v)
{
	int t=lca(u,v);
	return dep[u]-dep[t]+dep[v]-dep[t];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	log2n=log(n)/log(2)+0.5;
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		x=lca(a,b);
		y=lca(c,d);
		if(dis(a,y)+dis(b,y)==dis(a,b)||dis(c,x)+dis(d,x)==dis(c,d))
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
