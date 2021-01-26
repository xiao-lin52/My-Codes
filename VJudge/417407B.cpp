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
const int N = 200+10, M = 2000+10, inf = 0x3f3f3f3f;
struct Edge
{
	int nxt;
	int to;
	int flow;
};
Edge edge[M<<1];
int t, n, m, cnt, in[N], out[N], head[N], now[N], dep[N];
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
	memset(dep, 0, sizeof(dep));
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
			if(edge[i].flow && !dep[v])
			{
				dep[v] = dep[u]+1;
				now[v] = head[v];
				q.push(v);
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
			now[u] = i;
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
		mem(in, 0);
		mem(out, 0);
		scanf("%d%d", &n, &m);
		rep(i, 1, m)
		{
			int x, y, p;
			scanf("%d%d%d", &x, &y, &p);
			if(!p)
			{
				add_edge(x, y, 1);
				add_edge(y, x, 0);
			}
			in[y]++;
			out[x]++;
		}
		int num = 0, ans = 0;
		rep(i, 1, n)
			if((in[i]-out[i])%2)
			{
				printf("impossible\n");
				goto l;
			}
		rep(i, 1, n)
		{
			if(in[i] < out[i])
			{
				add_edge(0, i, (out[i]-in[i])/2);
				add_edge(i, 0, 0);
				num += (out[i]-in[i])/2;
			}
			if(in[i] > out[i])
			{
				add_edge(i, n+1, (in[i]-out[i])/2);
				add_edge(n+1, i, 0);
			}
		}
		while(bfs())
			ans += dfs(0, inf);
		if(ans == num)
			printf("possible\n");
		else
			printf("impossible\n");
		l:;
	}
	return 0;
}