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
const int N = 1100, M = 50010, inf = 0x3f3f3f3f;
struct Edge
{
	int nxt;
	int to;
	int flow;
};
Edge edge[M<<1];
int n, m, cnt, ans, num[N], s[N], last[N*10], dep[N], head[N], now[N];
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
	dep[0] = 1;
	now[0] = head[0];
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(int i = head[u]; ~i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if(edge[i].flow && !dep[v])
			{
				q.push(v);
				dep[v] = dep[u]+1;
				now[v] = head[v];
				if(v == n+1)
					return 1;
			}
		}
	}
	return 0;
}
int dfs(int u, int sum)
{
	if(u == n+1)
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
			if(!k)
				dep[v] = 0;
		}
	}
	return sum-rest;
}
int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d%d", &m, &n);
	rep(i, 1, m)
		scanf("%d", &num[i]);
	rep(i, 1, n)
	{
		int a, b, k;
		scanf("%d", &a);
		rep(j, 1, a)
		{
			scanf("%d", &k);
			if(!last[k])
			{
				add_edge(0, i, num[k]);
				add_edge(i, 0, 0);
			}
			else
			{
				add_edge(last[k], i, inf);
				add_edge(i, last[k], 0);
			}
			last[k] = i;
		}
		scanf("%d", &b);
		add_edge(i, n+1, b);
		add_edge(n+1, i, 0);
	}
	while(bfs())
		ans += dfs(0, inf);
	printf("%d", ans);
	return 0;
}