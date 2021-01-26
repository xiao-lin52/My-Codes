#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 610, M = 250010, inf = 0x3f3f3f3f;
struct Edge
{
	int nxt;
	int to;
	int flow;
};
Edge edge[M<<1];
int n, f, d, cnt, ans, head[N], dep[N], now[N];
void add_edge(int u, int v, int c)
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
	now[0] = head[0];
	dep[0] = 1;
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
				if(v == n+n+f+d+1)
					return 1;
			}
		}
	}
	return 0;
}
int dfs(int u, int sum)
{
	if(u == n+n+f+d+1)
		return sum;
	int rest = sum;
	for(int i = now[u]; ~i && rest; i = edge[i].nxt)
	{
		int v = edge[i].to;
		if(edge[i].flow && dep[v] == dep[u]+1)
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
int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &f, &d);
	rep(i, 1, n)
	{
		add_edge(i+f, i+f+n, 1);
		add_edge(i+f+n, i+f, 0);
		int s1, s2, y;
		scanf("%d%d", &s1, &s2);
		rep(j, 1, s1)
		{
			scanf("%d", &y);
			add_edge(y, i+f, 1);
			add_edge(i+f, y, 0);
		}
		rep(j, 1, s2)
		{
			scanf("%d", &y);
			add_edge(i+f+n, y+f+n+n, 1);
			add_edge(y+f+n+n, i+f+n, 0);
		}
	}
	rep(i, 1, f)
	{
		add_edge(0, i, 1);
		add_edge(i, 0, 0);
	}
	rep(i, 1, d)
	{
		add_edge(i+f+n+n, n+n+f+d+1, 1);
		add_edge(n+n+f+d+1, i+f+n+n, 0);
	}
	while(bfs())
		ans += dfs(0, inf);
	printf("%d", ans);
	return 0;
}