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
#define dist(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
using namespace std;
typedef long long ll;
const int N = 1e5+10, M = 1e6+10, inf = 0x3f3f3f3f;
struct Rubbish
{
	int x;
	int y;
	int c;
};
struct Edge
{
	int nxt;
	int to;
	int flow;
};
Edge edge[M<<1];
Rubbish a[N];
int n, m, d, w, s, t, cnt, vis[N], head[N], now[N], dep[N];
inline void add_edge(int u, int v, int c)
{
	edge[cnt].nxt = head[u];
	edge[cnt].to = v;
	edge[cnt].flow = c;
	head[u] = cnt++;
}
inline void add(int u, int v, int c)
{
	add_edge(u, v, c);
	add_edge(v, u, 0);
}
inline int check()
{
	queue<int> q;
	rep(i, 1, n)
		if(a[i].y <= d)
			q.push(i), vis[i] = 1;
	while(q.size())
	{
		int u = q.front();
		if(a[u].y+d >= w)
			return 1;
		q.pop();
		rep(i, 1, n)
			if(!vis[i] && dist(a[u].x, a[u].y, a[i].x, a[i].y) <= d)
			{
				vis[i] = 1;
				q.push(i);
			}
	}
	return 0;
}
inline void build(int k)
{
	t = 2*n*k+1;
	cnt = 0;
	mem(head, -1);
	rep(i, 1, n)
	{
		if(a[i].y <= d)
			rep(j, 1, k)
				add(s, (j-1)*2*n+i, inf);
		add(i, i+n, a[i].c);
	}
	rep(i, 2, k)
	{
		rep(j, 1, n)
			add((i-1)*2*n+j, (i*2-1)*n+j, a[j].c);
		rep(j, 1, n)
			rep(l, 1, n)
				if(dist(a[j].x, a[j].y, a[l].x, a[l].y) <= d)
					add(i*2*n-3*n+j, i*2*n-2*n+l, inf);
	}
	rep(i, 1, n)
		if(a[i].y+d >= w)
			rep(j, 1, k)
				add((j*2-1)*n+i, t, inf);
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
int dinic()
{
	int res = 0;
	while(bfs())
		res += dfs(s, inf);
	return res >= m;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &d, &w);
	rep(i, 1, n)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
	if(d >= w)
	{
		printf("1");
		return 0;
	}
	if(!check())
	{
		printf("IMPOSSIBLE");
		return 0;
	}
	rep(i, 1, n+m)
	{
		build(i);
		if(dinic())
		{
			printf("%d", i+1);
			return 0;
		}
	}
	printf("IMPOSSIBLE");
	return 0;
}