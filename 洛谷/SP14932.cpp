#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[2001];
int t,n,m,q,cnt,log2n,head[1001],dep[1001],fa[1001][11];
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
int main()
{
	scanf("%d",&t);
	for(int l=1;l<=t;l++)
	{
		cnt=0;
		memset(fa,0,sizeof(fa));
		memset(dep,0,sizeof(dep));
		memset(edge,0,sizeof(edge));
		memset(head,0,sizeof(head));
		printf("Case %d:\n",l);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=1;j<=m;j++)
			{
				int v;
				scanf("%d",&v);
				add_edge(i,v);
				add_edge(v,i);
			}
		}
		log2n=log(n)/log(2)+0.5;
		dfs(1,0);
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",lca(a,b));
		}
	}
	return 0;
}
