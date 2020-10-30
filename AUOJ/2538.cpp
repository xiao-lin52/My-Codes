#include<bits/stdc++.h>
#define N 1000010
#define M 100010
namespace IO
{
	template <typename T> inline void read(T &x)
	{
		x=0;
		register char c=getchar();
		while(c<'0'||c>'9')
			c=getchar();
		while(c>='0'&&c<='9')
			x=x*10+c-'0',c=getchar();
	}
}
using namespace IO;
using namespace std;
int n,m,k,ans,col[N],dep[N],num[N],sum[N],fa[N],siz[N],top[N],son[N],rk[N],id[N],mxdep[N][4];
vector<int> edge[N],color[M];
void dfs1(int u,int father)
{
	fa[u]=father;
	rk[++k]=u;
	id[u]=k;
	siz[u]=1;
	num[u]=1;
	mxdep[u][3]=mxdep[u][0]=1;
	dep[u]=dep[fa[u]]+1;
	color[col[u]].push_back(id[u]);
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=father)
		{
			dfs1(v,u);
			son[u]=siz[v]>siz[son[u]] ? v : son[u];
			if(mxdep[v][0]+1>mxdep[u][0])
			{
				mxdep[u][2]=mxdep[u][0];
				mxdep[u][0]=mxdep[v][0]+1;
				mxdep[u][1]=v;
				continue;
			}
			if(mxdep[v][0]+1>mxdep[u][2])
				mxdep[u][2]=mxdep[v][0]+1;
		}
	}
}
void dfs2(int u,int t)
{
	top[u]=t;
	if(son[u])
		dfs2(son[u],t);
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa[u]&&v!=son[u])
			dfs2(v,v);
	}
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])
		swap(u,v);
	return u;
}
void dfs3(int u,int fa)
{
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa)
		{
			if(v!=mxdep[u][1])
				mxdep[v][3]=max(mxdep[u][3],mxdep[u][0])+1;
			else
				mxdep[v][3]=max(mxdep[u][3],mxdep[u][2])+1;
			dfs3(v,u);
			sum[u]+=sum[v];
			num[u]+=num[v];
			if(!sum[v])
				ans=max(ans,mxdep[v][0]+1);
		}
	}
	if(num[u]==m)
		ans=max(ans,mxdep[u][3]);
}
signed main()
{
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		read(col[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		read(u);
		read(v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		sort(color[i].begin(),color[i].end());
		int Lca=rk[color[i][0]];
		for(int j=1;j<color[i].size();j++)
			Lca=lca(Lca,rk[color[i][j]]);
		sum[Lca]++;
	}
	for(int i=1;i<=m;i++)
	{
		if(color[i].size()==1)
		{
			num[rk[color[i][0]]]--;
			continue;
		}
		for(int j=1;j<color[i].size();j++)
			num[lca(rk[color[i][j-1]],rk[color[i][j]])]--;
	}
	dfs3(1,0);
	printf("%d",ans);
	return 0;
}