#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
using namespace std;
typedef long long ll;
const int N = 1e7+10, M = 1e5+10, inf = 0x3f3f3f3f;
int n, m, tot, nxt[N][5], qwq[N][5], fail[N], e[N], tag[N], ans[N];
char t[N], s[M][110];
vector<int> edge[N];
int getval(char x)
{
	return x == 'E' ? 1 : (x == 'S' ? 2 : (x == 'W' ? 3 : 4));
}
void insert(int x, char str[])
{
	int p = 0;
	rep(i, 1, strlen(str+1))
	{
		int s = getval(str[i]);
		if(!nxt[p][s])
			nxt[p][s] = ++tot;
		p = nxt[p][s];
	}
	e[p] = x;
}
void build()
{
	queue<int> q;
	rep(i, 1, 4)
		if(nxt[0][i])
			q.push(nxt[0][i]);
	while(q.size())
	{
		int p = q.front();
		q.pop();
		rep(i, 1, 4)
			if(nxt[p][i])
				fail[nxt[p][i]] = nxt[fail[p]][i], q.push(nxt[p][i]);
			else
				nxt[p][i] = nxt[fail[p]][i];
	}
	rep(i, 1, tot)
		edge[fail[i]].push_back(i);
}
int dfs(int u)
{
	rep(i, 0, edge[u].size()-1)
		tag[u] |= dfs(edge[u][i]);
	return tag[u];
}
void query()
{
	int p = 0;
	rep(i, 1, strlen(t+1))
	{
		int s = getval(t[i]);
		p = nxt[p][s];
		tag[p] = 1;
	}
	dfs(0);
}
void solve(int x)
{
	int p = 0;
	rep(i, 1, strlen(s[x]+1))
	{
		int t = getval(s[x][i]);
		p = nxt[p][t];
		if(tag[p])
			ans[x] = max(ans[x], i);
	}
}
int main()
{
	scanf("%d%d%s", &n, &m, t+1);
	rep(i, 1, m)
	{
		scanf("%s", s[i]+1);
		insert(i, s[i]);
	}
	build();
	query();
	rep(i, 1, m)
	{
		solve(i);
		printf("%d\n", ans[i]);
	}
	return 0;
}