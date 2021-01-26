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
const int N = 500+10, M = 1e5+10, inf = 0x3f3f3f3f;
struct Edge
{
	int nxt;
	int to;
	int flow;
};
Edge edge[M<<1];
int n, cnt, s, t, num, w[N], r[N], a[N][N], id[N][N], head[N], now[N], dep[N];
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
	return res == num;
}
int main()
{
	mem(head, -1);
	scanf("%d", &n);
	rep(i, 1, n)
		scanf("%d", &w[i]);
	rep(i, 1, n)
	{
		scanf("%d", &r[i]);
		if(i != 1 && w[i] > w[1]+r[1])
		{
			printf("NO");
			return 0;
		}
	}
	rep(i, 1, n)
		rep(j, 1, n)
			scanf("%d", &a[i][j]);
	int qwq = 0;
	rep(i, 2, n)
		rep(j, 2, i-1)
			id[i][j] = ++qwq;
	rep(i, 2, n)
		rep(j, 2, i-1)
		{
			add(s, id[i][j], a[i][j]);
			num += a[i][j];
			add(id[i][j], qwq+i-1, inf);
			add(id[i][j], qwq+j-1, inf);
		}
	t = qwq+n;
	rep(i, 2, n)
		add(qwq+i-1, t, w[1]+r[1]-w[i]);
	if(dinic())
		printf("YES");
	else
		printf("NO");
	return 0;
}