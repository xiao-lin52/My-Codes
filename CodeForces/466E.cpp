#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,k1,log2n,in[N],col[N][2],q[N][2],fa[N][20],dep[N],belong[N],f[N];
vector<int> edge[N];
int find(int x)
{
	return f[x]==x ? f[x] : f[x]=find(f[x]);
}
void dfs(int u,int father,int p)
{
	belong[u]=p;
	fa[u][0]=father;
	dep[u]=dep[father]+1;
	for(int i=1;(1<<i)<=dep[u];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=father)
			dfs(v,u,p);
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
		for(int i=0;i<=log2n;i++)
			if((depu-depv)&(1<<i))
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			edge[y].push_back(x);
			f[x]=find(y);
			in[x]++;
		}
		if(op==2)
		{
			k++;
			col[k][0]=x;
			col[k][1]=find(x);
		}
		if(op==3)
		{
			k1++;
			scanf("%d",&y);
			q[k1][0]=x;
			q[k1][1]=y;
		}
	}
	log2n=log(n)/log(2)+0.5;
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(!in[i])
			dfs(i,0,++cnt);
	for(int i=1;i<=k1;i++)
	{
		if(find(col[q[i][1]][1])==find(q[i][0])&&lca(col[q[i][1]][0],q[i][0])==q[i][0]&&lca(col[q[i][1]][1],q[i][0])==col[q[i][1]][1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
