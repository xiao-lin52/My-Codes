#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[201];
int n,cnt,u,v,log2n,depth,width,mid,head[101],dep[101],s[101],fa[101][11];
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
	for(int i=1;(1<<i)<=n;i++)
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
		if(fa[u][i]!=fa[v][i]&&fa[u][i]>0)
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
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	scanf("%d%d",&u,&v);
	log2n=log(n)/log(2)+0.5;
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		depth=max(dep[i],depth);
		s[dep[i]]++;
	}
	for(int i=1;i<=depth;i++)
		width=max(width,s[i]);
	mid=lca(u,v);
	printf("%d\n%d\n%d",depth,width,2*(dep[u]-dep[mid])+(dep[v]-dep[mid]));
	return 0;
}
