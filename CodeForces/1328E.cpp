#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,log2n,point[N],fa[N][20],dep[N];
vector<int> edge[N];
bool cmp(int a,int b)
{
	return dep[a]<dep[b];
}
void dfs(int u,int father)
{
	fa[u][0]=father;
	dep[u]=dep[fa[u][0]]+1;
	for(int i=1;(1<<i)<=dep[u];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa[u][0])
			dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	int depu=dep[u],depv=dep[v];
	for(int i=0;i<=log2n;i++)
		if((depu-depv)&(1<<i))
			u=fa[u][i];
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	fa[1][0]=1;
	log2n=log(n)/log(2)+0.5;
	for(int i=1;i<=m;i++)
	{
		int s,x,flag=1;
		scanf("%d",&s);
		for(int j=1;j<=s;j++)
		{
			scanf("%d",&x);
			point[j]=fa[x][0];
		}
		sort(point+1,point+1+s,cmp);
		for(int j=1;j<=s-1;j++)
			if(lca(point[j],point[j+1])!=point[j])
			{
				flag=0;
				break;
			}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
