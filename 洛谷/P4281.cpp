#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[1000001];
int n,m,cnt,log2n,head[500001],dep[500001],fa[500001][21];
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
int LCA(int u,int v)
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
int dis(int u,int v,int lca)
{
	return dep[u]-dep[lca]+dep[v]-dep[lca];
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
		int x,y,z,lca1,lca2,lca3;
		scanf("%d%d%d",&x,&y,&z);
		lca1=LCA(x,y);
		lca2=LCA(y,z);
		lca3=LCA(x,z);
		if(dep[lca1]>dep[lca2]&&dep[lca1]>dep[lca3])
			printf("%d %d\n",lca1,dis(x,y,lca1)+dis(lca1,z,LCA(lca1,z)));
		if(dep[lca2]>dep[lca1]&&dep[lca2]>dep[lca3])
			printf("%d %d\n",lca2,dis(y,z,lca2)+dis(lca2,x,LCA(lca2,x)));
		if(dep[lca3]>dep[lca1]&&dep[lca3]>dep[lca2])
			printf("%d %d\n",lca3,dis(x,z,lca3)+dis(lca3,y,LCA(lca3,y)));
		if(dep[lca1]==dep[lca2]&&dep[lca2]==dep[lca3])
			printf("%d %d\n",lca1,dis(x,y,lca1)+dis(lca1,z,LCA(lca1,z)));
	}
	return 0;
}
