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
const int N = 1000+10, M = 5e5+10, inf = 0x3f3f3f3f;
struct Edge
{
	int nxt;
	int to;
	int flow;
};
Edge edge[M<<1];
int k, n, m, s, t, cnt, a[N], head[N], now[N], dep[N];
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
	return res;
}
int main()
{
	mem(head, -1);
	scanf("%d%d%d%d%d", &k, &n, &m, &s, &t);
	if(s == t)
	{
		printf("NO");
		return 0;
	}
	rep(i, 1, n)
	{
		scanf("%d", &a[i]);
		add(i, i+n, a[i]);
	}
	rep(i, 1, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u+n, v, inf);
		add(v+n, u, inf);
	}
	s += n;
	if(dinic() <= k)
		printf("YES");
	else
		printf("NO");
	return 0;
}