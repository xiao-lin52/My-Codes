#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
using namespace std;
typedef long long ll;
const int N = 2e6+10, inf = 0x3f3f3f3f;
int n, tot, nxt[N][30], e[N], f[N], fail[N], tag[N], ans[N];
char s[N], t[N];
vector<int> edge[N];
void insert(int x, char str[])
{
	int len = strlen(str+1), p = 0;
	rep(i, 1, len)
	{
		if(!nxt[p][str[i]-'a'+1])
			nxt[p][str[i]-'a'+1] = ++tot;
		p = nxt[p][str[i]-'a'+1];
	}
	if(e[p])
		f[x] = e[p];
	else
		e[p] = x;
}
void build()
{
	queue<int> q;
	rep(i, 1, 26)
		if(nxt[0][i])
			q.push(nxt[0][i]);
	while(q.size())
	{
		int p = q.front();
		q.pop();
		rep(i, 1, 26)
			if(nxt[p][i])
				fail[nxt[p][i]] = nxt[fail[p]][i], q.push(nxt[p][i]);
			else
				nxt[p][i] = nxt[fail[p]][i];
	}
	rep(i, 1, tot)
		edge[fail[i]].push_back(i);
}
void query()
{
	int p = 0;
	rep(i, 1, strlen(t+1))
	{
		p = nxt[p][t[i]-'a'+1];
		tag[p]++;
	}
}
void dfs(int u)
{
	rep(i, 0, edge[u].size()-1)
	{
		dfs(edge[u][i]);
		tag[u] += tag[edge[u][i]];
	}
	if(e[u])
		ans[e[u]] = tag[u];
}
int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
		f[i] = i;
	rep(i, 1, n)
	{
		scanf("%s", s+1);
		insert(i, s);
	}
	scanf("%s", t+1);
	build();
	query();
	dfs(0);
	rep(i, 1, n)
		printf("%d\n", ans[f[i]]);
	return 0;
}