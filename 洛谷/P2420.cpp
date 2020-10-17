#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[200001];
int n,m,cnt,log2n,mid,head[100001],dep[100001],fa[100001][21],sum[100001][21];
void add_edge(int u,int v,int c)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].w=c;
	head[u]=cnt;
}
void dfs(int u,int father)
{
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
		sum[u][i]=sum[u][i-1]^sum[fa[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=edge[i].next)
		if(edge[i].to!=father)
		{
			sum[edge[i].to][0]=edge[i].w;
			dfs(edge[i].to,u);
		}
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
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	scanf("%d",&m);
	log2n=log(n)/log(2)+0.5;
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int x,y,ans=0;
		scanf("%d%d",&x,&y);
		mid=lca(x,y);
		int depx=dep[x],depy=dep[y];
		for(int j=0;(1<<j)<=depx-dep[mid];j++)
			if((1<<j)&(depx-dep[mid]))
			{
				ans^=sum[x][j];
				x=fa[x][j];
			}
		for(int j=0;(1<<j)<=depy-dep[mid];j++)
			if((1<<j)&(depy-dep[mid]))
			{
				ans^=sum[y][j];
				y=fa[y][j];
			}
		printf("%d\n",ans);
	}
	return 0;
}
