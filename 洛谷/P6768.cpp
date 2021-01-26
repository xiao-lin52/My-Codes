#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
using namespace std;
typedef long long ll;
const int N = 510, M = 50010;
const ll inf = 1e18;
struct Edge
{
	int nxt;
	int to;
	ll flow;
};
Edge edge[M<<1], tmp[M<<1];
int n, m, cnt, num, head[N], dep[N], now[N], a[N][2];
ll dis[N][N], l, r, mid;
void add_edge(int u, int v, ll c)
{
	edge[cnt].nxt = head[u];
	edge[cnt].to = v;
	edge[cnt].flow = c;
	head[u] = cnt;
	cnt++;
}
int bfs()
{
	memset(dep, 0, sizeof(dep));
	queue<int> q;
	q.push(0);
	dep[0] = 1;
	now[0] = head[0];
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(int i = head[u]; ~i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if(edge[i].flow && !dep[v] && (u == 0 || u == 2*n+1 || v == 0 || v == 2*n+1 || dis[(u-1)%n+1][(v-1)%n+1] <= mid))
			{
				q.push(v);
				dep[v] = dep[u]+1;
				now[v] = head[v];
				if(v == 2*n+1)
					return 1;
			}
		}
	}
	return 0;
}
int dfs(int u, ll sum)
{
	if(u == 2*n+1)
		return sum;
	ll rest = sum;
	for(int i = now[u]; ~i && rest; i = edge[i].nxt)
	{
		int v = edge[i].to;
		if(edge[i].flow && dep[v] == dep[u]+1 && (u == 0 || u == 2*n+1 || v == 0 || v == 2*n+1 || dis[(u-1)%n+1][(v-1)%n+1] <= mid))
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
	memcpy(edge, tmp, sizeof(tmp));
	int ans = 0;
	while(bfs())
		ans += dfs(0, inf);
	if(ans == num)
		return 1;
	else
		return 0;
}
signed main()
{
	memset(dis, 0x3f, sizeof(dis));
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		dis[i][i] = dis[0][i] = dis[i][0] = dis[i][2*n+1] = dis[n+1][i] = 0;
	rep(i, 1, n)
	{
		scanf("%d%d", &a[i][0], &a[i][1]);
		num += a[i][0];
	}
	rep(i, 1, m)
	{
		int x, y;
		ll z;
		scanf("%d%d%lld", &x, &y, &z);
		dis[x][y] = dis[y][x] = min(dis[x][y], z);
	}
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	rep(i, 1, n)
	{
		add_edge(0, i, a[i][0]);
		add_edge(i, 0, 0);
		add_edge(i+n, 2*n+1, a[i][1]);
		add_edge(2*n+1, i+n, 0);
	}
	rep(i, 1, n)
		rep(j, 1, n)
			if(dis[i][j] < inf)
			{
				add_edge(i, j+n, inf);
				add_edge(j+n, i, 0);
				r = max(r, dis[i][j]);
			}
	memcpy(tmp, edge, sizeof(edge));
	mid = inf;
	if(!dinic())
	{
		printf("-1");
		return 0;
	}
	while(l < r)
	{
		mid = (l+r)>>1;
		if(dinic())
			r = mid;
		else
			l = mid+1;
	}
	printf("%lld", l);
	return 0;
}