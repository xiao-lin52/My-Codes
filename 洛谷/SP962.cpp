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
const int N = 1e5+10, M = 7e5+10, inf = 0x3f3f3f3f;
struct Edge
{
	int nxt;
	int to;
	int flow;
};
Edge edge[M<<1];
int t, n, m, cnt, head[N], now[N], dep[N];
inline void add_edge(int u, int v, int c)
{
	edge[cnt].nxt = head[u];
	edge[cnt].to = v;
	edge[cnt].flow = c;
	head[u] = cnt;
	cnt++;
}
inline int bfs()
{
	mem(dep, 0);
	queue<int> q;
	now[0] = head[0];
	dep[0] = 1;
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
				dep[v] = dep[u]+1;
				now[v] = head[v];
				q.push(v);
				if(v == 2*n+1)
					return 1;
			}
		}
	}
	return 0;
}
int dfs(int u, int sum)
{
	if(u == 2*n+1)
		return sum;
	int rest = sum;
	for(int i = now[u]; ~i && rest; i = edge[i].nxt)
	{
		int v = edge[i].to;
		if(dep[v] == dep[u]+1 && edge[i].flow)
		{
			int k = dfs(v, min(rest, edge[i].flow));
			edge[i].flow -= k;
			edge[i^1]. flow += k;
			now[u] = i;
			rest -= k;
			if(!k)
				dep[v] = 0;
		}
	}
	return sum-rest;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		cnt = 0;
		mem(head, -1);
		scanf("%d%d", &n, &m);
		rep(i, 1, n)
		{
			add_edge(2*i-1, 2*i, 1);
			add_edge(2*i, 2*i-1, 0);
		}
		rep(i, 1, m)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if(u < 1 || v < 1 || u > n || v > n)
				continue;
			add_edge(2*u, 2*v-1, 1);
			add_edge(2*v-1, 2*u, 0);
			add_edge(2*v, 2*u-1, 1);
			add_edge(2*u-1, 2*v, 0);
		}
		add_edge(0, 4, 2);
		add_edge(4, 0, 0);
		add_edge(1, 2*n+1, 1);
		add_edge(2*n+1, 1, 0);
		add_edge(5, 2*n+1, 1);
		add_edge(2*n+1, 5, 0);
		int ans = 0;
		while(bfs())
			ans += dfs(0, inf);
		if(ans == 2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}