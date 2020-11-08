#include<bits/stdc++.h>
#define pii pair<ll,ll>
#define mp make_pair
using namespace std;
typedef long long ll;
const ll N=5e3+10,inf=0x3f3f3f3f3f3f3f3f;
ll n,m,q,in[N],dis[N][N][2];
vector<ll> edge[N];
void bfs(ll s)
{
	queue<pii> q;
	q.push(mp(s,0));
	dis[s][s][0]=0;
	while(q.size())
	{
		ll u=q.front().first,p=q.front().second;
		q.pop();
		for(ll i=0;i<edge[u].size();i++)
		{
			ll v=edge[u][i];
			if(dis[s][v][p^1]==inf)
			{
				dis[s][v][p^1]=dis[s][u][p]+1;
				q.push(mp(v,p^1));
			}
		}
	}
}
signed main()
{
	memset(dis,inf,sizeof(dis));
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
		in[u]++;
		in[v]++;
	}
	for(ll i=1;i<=n;i++)
		bfs(i);
	for(ll i=1;i<=q;i++)
	{
		ll s,t,d;
		scanf("%lld%lld%lld",&s,&t,&d);
		if(dis[s][t][d&1]>d||((!in[s]||!in[t])&&d))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
