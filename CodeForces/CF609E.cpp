#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define int long long
using namespace std;
struct Edge
{
	int u;
	int v;
	int c;
	int id;
};
bool cmp(Edge a,Edge b)
{
	return a.c<b.c;
}
bool cmp2(Edge a,Edge b)
{
	return a.id<b.id;
}
Edge a[200001];
vector<pii> edge[200001];
int n,m,cnt,k,log2n,f[200001],dep[200001],fa[200001][21],maxn[200001][21];
int find(int x)
{
	return f[x]==x? f[x]:f[x]=find(f[x]);
}
void dfs(int u,int father)
{
	fa[u][0]=father;
	dep[u]=dep[father]+1;
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
		maxn[u][i]=max(maxn[u][i-1],maxn[fa[u][i-1]][i-1]);
	}
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i].first,c=edge[u][i].second;
		if(v!=father)
		{
			maxn[v][0]=c;
			dfs(v,u);
		}
	}
}
int lca(int u,int v)
{
	int depu=dep[u],depv=dep[v],ans=0;
	if(depu!=depv)
	{
		if(depu<depv)
		{
			swap(depu,depv);
			swap(u,v);
		}
		for(int i=0;(1<<i)<=depu-depv;i++)
			if((depu-depv)&(1<<i))
			{
				ans=max(ans,maxn[u][i]);
				u=fa[u][i];
			}
	}
	if(u==v)
		return ans;
	for(int i=log2n;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
		{
			ans=max(ans,max(maxn[u][i],maxn[v][i]));
			u=fa[u][i];
			v=fa[v][i];
		}
	return max(ans,max(maxn[u][0],maxn[v][0]));
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].c);
		a[i].id=i;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int t1=find(a[i].u),t2=find(a[i].v);
		if(t1!=t2)
		{
			f[t1]=t2;
			cnt++;
			k+=a[i].c;
			edge[a[i].u].push_back(mp(a[i].v,a[i].c));
			edge[a[i].v].push_back(mp(a[i].u,a[i].c));
		}
		if(cnt==n-1)
			break;
	}
	sort(a+1,a+1+m,cmp2);
	log2n=log(n)/log(2)+0.5;
	dfs(1,0);
	for(int i=1;i<=m;i++)
		printf("%lld\n",k+a[i].c-lca(a[i].u,a[i].v));
	return 0;
}
