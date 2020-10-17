#include<bits/stdc++.h>
using namespace std;
vector<int> edge[100001];
int n,m,log2n,dep[100001],p[100001],fa[100001][21][3];
string t;
void dfs(int u,int father)
{
	dep[u]=dep[father]+1;
	fa[u][0][0]=father;
	fa[u][0][p[father]]=1;
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		fa[u][i][0]=fa[fa[u][i-1][0]][i-1][0];
		fa[u][i][1]=fa[u][i-1][1]|fa[fa[u][i-1][0]][i-1][1];
		fa[u][i][2]=fa[u][i-1][2]|fa[fa[u][i-1][0]][i-1][2];
	}
	for(int i=0;i<edge[u].size();i++)
		if(edge[u][i]!=father)
			dfs(edge[u][i],u);
}
int LCA(int u,int v,int q)
{
	int depu=dep[u],depv=dep[v],ans=0;
	if(p[u]==q||p[v]==q)
		return 1;
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
				ans|=fa[u][i][q];
				u=fa[u][i][0];
			}
	}
	if(u==v)
		return ans;
	for(int i=log2n;i>=0;i--)
		if(fa[u][i][0]!=fa[v][i][0])
		{
			ans|=fa[u][i][q]|fa[v][i][q];
			u=fa[u][i][0];
			v=fa[v][i][0];
		}
	return ans|fa[u][0][q]|fa[v][0][q];
}
int main()
{
	cin>>n>>m>>t;
	for(int i=1;i<=t.length();i++)
		if(t[i-1]=='G')
			p[i]=1;
		else
			p[i]=2;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	log2n=log(n)/log(2)+0.5;
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		char x;
		cin>>u>>v>>x;
		if(x=='G')
			cout<<LCA(u,v,1);
		else
			cout<<LCA(u,v,2);
	}
	return 0;
}
