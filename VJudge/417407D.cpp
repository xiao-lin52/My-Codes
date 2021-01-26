#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
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
const int N = 200+10, M = 1e5+10, inf = 0x3f3f3f3f;
struct Edge
{
	int nxt;
	int to;
	int flow;
};
Edge edge[M<<1];
int t, n, cnt, d, num[N], head[N], now[N], dep[N], id[11][11];
string str;
inline void add_edge(int u, int v, int c)
{
	edge[cnt].nxt = head[u];
	edge[cnt].to = v;
	edge[cnt].flow = c;
	head[u] = cnt;
	cnt++;
}
inline void add(int u, int v, int c)
{
	add_edge(u, v, c);
	add_edge(v, u, 0);
}
inline void build(int k)
{
	cnt = 0;
	mem(head, -1);
	rep(i, 1, n)
		add(0, i, num[i]);
	rep(i, 1, d)
		add(n+i, n+d+1, 1);
	rep(i, 1, n)
		rep(j, 1, i-1)
		{
			if(num[i] < num[j] && i > n-k)
				add(i, n+id[i][j], 1);
			else if(num[i] > num[j] && j > n-k)
				add(j, n+id[i][j], 1);
			else
			{
				add(i, n+id[i][j], 1);
				add(j, n+id[i][j], 1);
			}
		}
}
inline int bfs()
{
	mem(dep, 0);
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
			if(!dep[v] && edge[i].flow)
			{
				dep[v] = dep[u]+1;
				now[v] = head[v];
				if(v == d+n+1)
					return 1;
				q.push(v);
			}
		}
	}
	return 0;
}
int dfs(int u, int sum)
{
	if(u == d+n+1)
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
		res += dfs(0, inf);
	return res == d;
}
int main()
{
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		n = 0;
		str.clear();
		getline(cin, str);
		int tmp = 0, flag;
		rep(i, 0, str.size()-1)
			if(str[i] == ' ')
			{
				num[++n] = tmp;
				tmp = 0;
				flag = 0;
			}
			else
			{
				flag = 1;
				tmp = tmp*10+str[i]-'0';
			}
		if(flag)
			num[++n] = tmp;
		sort(num+1, num+1+n);
		d = n*(n-1)/2;
		int qwq = 0;
		rep(i, 1, n)
			rep(j, 1, i-1)
				id[i][j] = id[j][i] = ++qwq;
		per(i, n, 0)
		{
			build(i);
			if(dinic())
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}