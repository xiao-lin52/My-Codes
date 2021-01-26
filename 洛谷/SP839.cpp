#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define mem(x, val) memset(x, val, sizeof(x))
#define debug(x) cerr<<#x<<" = "<<x
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 3000+10, M = 1e5+10, inf = 0x3f3f3f3f;
int t, n, m, k, u[N], v[N], p[N];
struct Edge
{
	int nxt;
	int to;
	int flow;
};
struct Graph
{
	int s, t, cnt, head[N], dep[N], now[N], vis[N];
	Edge edge[M<<1];
	inline void init()
	{
		s = 0;
		t = n+1;
		cnt = 0;
		mem(head, -1);
		mem(vis, 0);
	}
	inline void add_edge(int u, int v, int c)
	{
		edge[cnt].nxt = head[u];
		edge[cnt].to = v;
		edge[cnt].flow = c;
		head[u] = cnt++;
		edge[cnt].nxt = head[v];
		edge[cnt].to = u;
		edge[cnt].flow = 0;
		head[v] = cnt++;
	}
	inline int bfs()
	{
		mem(dep, 0);
		queue<int> q;
		q.push(s);
		dep[s] = 1;
		now[s] = head[s];
		while(q.size())
		{
			int u = q.front();
			q.pop();
			for(int i = head[u]; ~i; i = edge[i].nxt)
			{
				int v = edge[i].to;
				if(!dep[v] && edge[i].flow)
				{
					dep[v] = dep[u]+1;
					now[v] = head[v];
					if(v == t)
						return 1;
					q.push(v);
				}
			}
		}
		return 0;
	}
	int dfs(int u, int sum)
	{
		if(u == t)
			return sum;
		int rest = sum;
		for(int i = now[u]; ~i && rest; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if(dep[v] == dep[u]+1 && edge[i].flow)
			{
				int k = dfs(v, min(rest, edge[i].flow));
				edge[i].flow -= k;
				edge[i^1].flow += k;
				rest -= k;
				now[u] = i;
				if(!k)
					dep[v] = 0;
			}
		}
		return sum-rest;
	}
	void dinic()
	{
		int res = 0;
		while(bfs())
			res += dfs(s, inf);
	}
	void solve(int u, int k)
	{
		p[u] += 1ll<<k;
		vis[u] = 1;
		for(int i = head[u]; ~i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if(edge[i].flow && !vis[v])
				solve(v, k);
		}
	}
};
Graph g[50];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		mem(p, 0);
		scanf("%d%d", &n, &m);
		rep(i, 0, 30)
			g[i].init();
		rep(i, 1, m)
			scanf("%d%d", &u[i], &v[i]);
		scanf("%d", &k);
		rep(i, 1, k)
		{
			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);
			per(j, 30, 0)
				if((y>>j)&1)
					g[j].add_edge(g[j].s, x, inf);
				else
					g[j].add_edge(x, g[j].t, inf);
		}
		rep(i, 0, 30)
			rep(j, 1, m)
			{
				g[i].add_edge(u[j], v[j], 1);
				g[i].add_edge(v[j], u[j], 1);
			}
		rep(i, 0, 30)
		{
			g[i].dinic();
			g[i].solve(g[i].s, i);
		}
		rep(i, 1, n)
			printf("%d\n", p[i]);
	}
	return 0;
}