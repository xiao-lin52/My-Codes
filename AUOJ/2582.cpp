#include<bits/stdc++.h>
#define pii pair<ll,ll>
#define mp make_pair
using namespace std;
typedef long long ll;
const ll N=110,inf=0x3f3f3f3f;
ll t,n,m,l,r,dis[N],cnt[N],vis[N],p[N][N];
vector<pii> edge[N];
ll check(ll val)
{
	memset(dis,inf,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	queue<ll> q;
	q.push(1);
	vis[1]=1;
	dis[1]=0;
	cnt[1]++;
	while(q.size())
	{
		ll u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<edge[u].size();i++)
		{
			ll v=edge[u][i].first,c=edge[u][i].second+val;
			if(dis[v]>dis[u]+c&&p[1][u]&&p[v][n])
			{
				dis[v]=dis[u]+c;
				if(!vis[v])
				{
					cnt[v]++;
					if(cnt[v]>n)
						return 0;
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	if(dis[n]<0)
		return 0;
	else
		return 1;
}
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		memset(p,0,sizeof(p));
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			edge[i].clear();
			p[i][i]=1;
		}
		l=1000000;
		r=-1000000;
		for(int i=1;i<=m;i++)
		{
			ll u,v,c;
			scanf("%lld%lld%lld",&u,&v,&c);
			edge[u].push_back(mp(v,c));
			p[u][v]=1;
			l=min(l,-c);
			r=max(r,-c);
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					p[i][j]|=p[i][k]&p[k][j];
		if(!p[1][n])
		{
			printf("-1\n");
			continue;
		}
		while(l<r)
		{
			ll mid=(l+r)>>1;
			if(check(mid))
				r=mid;
			else
				l=mid+1;
		}
		check(l);
		printf("%lld\n",dis[n]);
	}
	return 0;
}