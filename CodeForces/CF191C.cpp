#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int next;
	int to;
	int id;
	int p;
};
Edge edge[200001];
int n,m,cnt,log2n,head[100001],ans[100001],dep[100001],p[100001],sum[100001],fa[100001][21];
void add_edge(int u,int v,int x)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].id=x;
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
void work(int u,int father)
{
	for(int i=head[u];i;i=edge[i].next)
		if(edge[i].to!=father)
		{
			work(edge[i].to,u);
			sum[u]+=sum[edge[i].to];
			ans[edge[i].id]=sum[edge[i].to];
		}
	sum[u]+=p[u];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y,i);
		add_edge(y,x,i);
	}
	log2n=log(n)/log(2)+0.5;
	dfs(1,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		p[a]++;
		p[b]++;
		p[LCA(a,b)]-=2;
	}
	work(1,0);
	for(int i=1;i<=n-1;i++)
		printf("%d ",ans[i]);
	return 0;
}
