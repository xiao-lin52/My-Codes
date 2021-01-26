#include <bits/stdc++.h>
#define rep(i, l, r) for(ll i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(ll i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
#define pii pair<ll, ll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll N = 210, M = 5010, inf = LONG_LONG_MAX;
struct Edge
{
	ll nxt;
	ll to;
	ll flow;
};
Edge edge[M<<1];
ll n, m, s, t, cnt, ans, head[N], dep[N], now[N];
void add_edge(ll u, ll v, ll c)
{
	edge[cnt].nxt = head[u];
	edge[cnt].to = v;
	edge[cnt].flow = c;
	head[u] = cnt;
	cnt++;
}
ll bfs()
{
	memset(dep, 0, sizeof(dep));
	queue<ll> q;
	q.push(s);
	dep[s] = 1;
	now[s] = head[s];
	while(q.size())
	{
		ll u = q.front();
		q.pop();
		for(ll i = head[u]; ~i; i = edge[i].nxt)
		{
			ll v = edge[i].to;
			if(!dep[v] && edge[i].flow)
			{
				q.push(v);
				dep[v] = dep[u]+1;
				now[v] = head[v];
				if(v == t)
					return 1;
			}
		}
	}
	return 0;
}
ll dfs(ll u, ll sum)
{
	if(u == t)
		return sum;
	ll rest = sum;
	for(ll i = now[u]; ~i && rest; i = edge[i].nxt)
	{
		ll v = edge[i].to;
		if(edge[i].flow && dep[v] == dep[u]+1)
		{
			ll k = dfs(v, min(edge[i].flow, rest));
			if(!k)
				dep[v] = 0;
			edge[i].flow -= k;
			edge[i^1].flow += k;
			rest -= k;
			now[u] = i;
		}
	}
	return sum-rest;
}
signed main()
{
	memset(head, -1, sizeof(head));
	scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
	rep(i, 1, m)
	{
		ll x, y;
		ll z;
		scanf("%lld%lld%lld", &x, &y, &z);
		add_edge(x, y, z);
		add_edge(y, x, 0);
	}
	while(bfs())
		ans += dfs(s, inf);
	printf("%lld", ans);
	return 0;
}