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
const int N = 1e3+10, inf = 0x3f3f3f3f;
struct Edge
{
	int nxt;
	int to;
	int flow;
};
Edge edge[N*N*2];
int t, n, m, k, cnt, h[N], u[N], v[N], head[N], now[N], dep[N];
inline void add_edge(int u, int v, int c)
{
	edge[cnt].nxt = head[u];
	edge[cnt].to = v;
	edge[cnt].flow = c;
	head[u] = cnt;
	cnt++;
}
inline void build(int val)
{
	cnt = 0;
	mem(head, -1);
	rep(i, 1, k)
	{
		add_edge(0, h[i], 1);
		add_edge(h[i], 0, 0);
	}
	rep(i, 1, m)
	{
		add_edge(u[i], v[i], val);
		add_edge(v[i], u[i], val);
	}
}
inline int bfs()
{
	mem(dep, 0);
	queue<int> q;
	dep[0] = 1;
	now[0] = head[0];
	q.push(0);
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(int i = head[u]; ~i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if(!dep[v] && edge[i].flow)
			{
				q.push(v);
				dep[v] = dep[u]+1;
				now[v] = head[v];
				if(v == 1)
					return 1;
			}
		}
	}
	return 0;
}
int dfs(int u, int sum)
{
	if(u == 1)
		return sum;
	int rest = sum;
	for(int i = now[u]; ~i && rest; i = edge[i].nxt)
	{
		int v = edge[i].to;
		if(dep[v] == dep[u]+1 && edge[i].flow)
		{
			int tmp = dfs(v, min(rest, edge[i].flow));
			now[u] = i;
			if(tmp <= 0)
				continue;
			edge[i].flow -= tmp;
			edge[i^1].flow += tmp;
			rest -= tmp;
			if(!k)
				dep[v] = 0;
		}
	}
	return sum-rest;
}
inline int dinic()
{
	int ans = 0;
	while(bfs())
		ans += dfs(0, inf);
	if(ans == k)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &n, &m, &k);
		rep(i, 1, k)
			scanf("%d", &h[i]);
		rep(i, 1, m)
			scanf("%d%d", &u[i], &v[i]);
		int l = 1, r = k;
		while(l < r)
		{
			int mid = (l+r)>>1;
			build(mid);
			if(dinic())
				r = mid;
			else
				l = mid+1;
		}
		printf("%d\n", l);
	}
	return 0;
}