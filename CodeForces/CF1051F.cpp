#include<bits/stdc++.h>
#define pii pair<long long,long long>
#define mp(a,b) make_pair(a,b)
using namespace std;
struct MST
{
	long long u;
	long long v;
	long long c;
	long long f;
};
bool cmp(MST a,MST b)
{
	return a.c<b.c;
}
MST a[100001];
vector<pii> edge[100001],edge2[100001];
long long n,m,q,cnt,log2n,f[100001],dep[100001],fa[100001][21],sum[100001][21];
long long n1,m1,p[51],v[100001],dis[51][100001],b[51][100001];
long long find(long long x)
{
	return f[x]==x? f[x]:f[x]=find(f[x]);
}
void dfs(long long u,long long father)
{
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	for(long long i=1;(1<<i)<=dep[u];i++)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
		sum[u][i]=sum[u][i-1]+sum[fa[u][i-1]][i-1];
	}
	for(long long i=0;i<edge[u].size();i++)
		if(edge[u][i].first!=father)
		{
			sum[edge[u][i].first][0]=edge[u][i].second;
			dfs(edge[u][i].first,u);
		}
}
long long lca(long long u,long long v)
{
	long long depu=dep[u],depv=dep[v],s=0;
	if(depu!=depv)
	{
		if(depu<depv)
		{
			swap(depu,depv);
			swap(u,v);
		}
		for(long long i=0;(1<<i)<=depu-depv;i++)
			if((1<<i)&(depu-depv))
			{
				s+=sum[u][i];
				u=fa[u][i];
			}
	}
	if(u==v)
		return s;
	for(long long i=log2n;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
		{
			s+=sum[u][i];
			s+=sum[v][i];
			u=fa[u][i];
			v=fa[v][i];
		}
	return s+sum[u][0]+sum[v][0];
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		f[i]=i;
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].c);
		edge2[a[i].u].push_back(mp(a[i].v,a[i].c));
		edge2[a[i].v].push_back(mp(a[i].u,a[i].c));
	}
	sort(a+1,a+1+m,cmp);
	for(long long i=1;i<=m;i++)
	{
		long long t1=find(a[i].u),t2=find(a[i].v);
		if(t1!=t2)
		{
			f[t1]=t2;
			cnt++;
			a[i].f=1;
			edge[a[i].u].push_back(mp(a[i].v,a[i].c));
			edge[a[i].v].push_back(mp(a[i].u,a[i].c));
		}
		if(cnt==n-1)
			break;
	}
	for(long long i=1;i<=m;i++)
		if(!a[i].f)
		{
			if(!v[a[i].u])
				p[++n1]=a[i].u;
			if(!v[a[i].v])
				p[++n1]=a[i].v;
			v[a[i].u]=v[a[i].v]=1;
		}
	memset(dis,0x3f,sizeof(dis));
	for(long long s=1;s<=n1;s++)
	{
		priority_queue< pii,vector<pii>,greater<pii> > q;
		dis[s][p[s]]=0;
		q.push(mp(0,p[s]));
		while(q.size())
		{
			long long u=q.top().second;
			q.pop();
			if(b[s][u])
				continue;
			b[s][u]=1;
			for(long long i=0;i<edge2[u].size();i++)
			{
				long long y=edge2[u][i].first,c=edge2[u][i].second;
				if(dis[s][y]>dis[s][u]+c)
				{
					dis[s][y]=dis[s][u]+c;
					q.push(mp(dis[s][y],y));
				}
			}
		}
	}
	log2n=log(n)/log(2)+0.5;
	dfs(1,0);
	scanf("%lld",&q);
	for(long long i=1;i<=q;i++)
	{
		long long u,v,ans;
		scanf("%lld%lld",&u,&v);
		ans=lca(u,v);
		for(long long j=1;j<=n1;j++)
			ans=min(ans,dis[j][u]+dis[j][v]);
		printf("%lld\n",ans);
	}
	return 0;
}
