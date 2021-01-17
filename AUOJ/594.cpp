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
const int N = 1e6+10, inf = 0x3f3f3f3f;
int n, tot, ans, trie[N][30], fail[N], e[N], tag[N];
char t[N], s[N];
vector<int> edge[N];
void insert(char str[])
{
	int p = 0;
	rep(i, 1, strlen(t+1))
	{
		int q = str[i]-'a'+1;
		if(!trie[p][q])
			trie[p][q] = ++tot;
		p = trie[p][q];
	}
	e[p] = 1;
}
void build()
{
	queue<int> q;
	rep(i, 1, 26)
		if(trie[0][i])
			q.push(trie[0][i]);
	int p = 0;
	while(q.size())
	{
		int p = q.front();
		q.pop();
		rep(i, 1, 26)
			if(trie[p][i])
				fail[trie[p][i]] = trie[fail[p]][i], q.push(trie[p][i]);
			else
				trie[p][i] = trie[fail[p]][i];
	}
	rep(i, 1, tot)
		edge[fail[i]].pb(i);
}
int dfs(int u)
{
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		tag[u] |= dfs(v);
	}
	if(e[u] && tag[u])
		ans++;
	return tag[u];
}
void query()
{
	int p = 0;
	rep(i, 1, strlen(s+1))
	{
		int q = s[i]-'a'+1;
		p = trie[p][q];
		tag[p] = 1;
	}
	dfs(0);
}
int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
	{
		scanf("%s", t+1);
		insert(t);
	}
	scanf("%s", s+1);
	build();
	query();
	printf("%d", ans);
	return 0;
}