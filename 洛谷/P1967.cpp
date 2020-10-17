#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
struct tree_Edge
{
	int next;
	int to;
	int w;
};
struct Edge
{
	int u;
	int v;
	int c;
};
bool cmp(Edge a,Edge b)
{
	return a.c>b.c;
}
tree_Edge edge[200001];
Edge a[600001];
int n,m,q,k,p,l,cnt,log2n;
int head[100001],f[100001],dep[100001],v[100001],fa[100001][21],dp[100001][21];
void add_edge(int u,int v,int c)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].w=c;
	head[u]=cnt;
}
int find(int x)
{
	return f[x]==x? f[x]:f[x]=find(f[x]);
}
void dfs(int u,int father)
{
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
		dp[u][i]=min(dp[u][i-1],dp[fa[u][i-1]][i-1]);
	}
	for(int i=head[u];i;i=edge[i].next)
		if(edge[i].to!=father)
		{
			dp[edge[i].to][0]=edge[i].w;
			dfs(edge[i].to,u);
		}
}
int lca(int u,int v)
{
	int ans=inf,depu=dep[u],depv=dep[v];
	if(depu!=depv)
	{
		if(depu<depv)
		{
			swap(depu,depv);
			swap(u,v);
		}
		for(int i=0;(1<<i)<=depu-depv;i++)
			if((1<<i)&(depu-depv))
			{
				ans=min(ans,dp[u][i]);
				u=fa[u][i];
			}
	}
	if(u==v)
		return ans;
	for(int i=log2n;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
		{
			ans=min(ans,dp[u][i]);
			ans=min(ans,dp[v][i]);
			u=fa[u][i];
			v=fa[v][i];
		}
	ans=min(ans,dp[u][0]);
	ans=min(ans,dp[v][0]);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(dp,inf,sizeof(dp));
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int t1=find(a[i].u),t2=find(a[i].v);
		if(t1!=t2)
		{
			f[t1]=t2;
			k++;
			add_edge(a[i].u,a[i].v,a[i].c);
			add_edge(a[i].v,a[i].u,a[i].c);
		}
		if(k==n-1)
			break;
	}
	dfs(1,0);
	scanf("%d",&q);
	log2n=log(n)/log(2)+0.5;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)!=find(y))
			printf("-1\n");
		else
			printf("%d\n",lca(x,y));
	}
	return 0;
}