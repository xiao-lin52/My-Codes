#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[600001];
int n,cnt,log2n,head[300001],a[300001],dep[300001],p[300001],ans[300001],fa[300001][21];
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
void work(int u,int father)
{
	for(int i=head[u];i;i=edge[i].next)
		if(edge[i].to!=father)
		{
			work(edge[i].to,u);
			ans[u]+=ans[edge[i].to];
		}
	ans[u]+=p[u];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	log2n=log(n)/log(2)+0.5;
	dfs(1,0);
	for(int i=1;i<=n-1;i++)
	{
		int mid=lca(a[i],a[i+1]);
		p[a[i]]++;
		p[fa[a[i+1]][0]]++;
		p[mid]--;
		p[fa[mid][0]]--;
	}
	work(1,0);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}
