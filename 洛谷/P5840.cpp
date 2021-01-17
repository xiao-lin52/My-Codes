#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N = 2e6+10, inf = 0x3f3f3f3f;
int n, q, tot, k, trie[N][30], fail[N], e[N], match[N], node[N];
int cnt, fa[N], dep[N], dfn[N], rk[N], siz[N], son[N], top[N];
int tree[N];
vector<int> edge[N];
char s[N];
bool cmp(int x, int y)
{
	return dfn[x] < dfn[y];
}
void dfs1(int u, int f)
{
	cnt++;
	fa[u] = f;
	dep[u] = dep[f]+1;
	dfn[u] = cnt;
	rk[cnt] = u;
	siz[u] = 1;
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		dfs1(v, u);
		siz[u] += siz[v];
		son[u] = siz[son[u]] > siz[v] ? son[u] : v;
	}
}
void dfs2(int u, int t)
{
	top[u] = t;
	if(son[u])
		dfs2(son[u], t);
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		if(v != son[u])
			dfs2(v, v);
	}
}
int lca(int u, int v)
{
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
			swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}
void update(int x, int k)
{
	for(; x <= cnt; x += lowbit(x))
		tree[x] += k;
}
int query(int x)
{
	int ans = 0;
	for(; x >= 1; x -= lowbit(x))
		ans += tree[x];
	return ans;
}
void insert(int x, char str[])
{
	int p = 0;
	rep(i, 1, strlen(str+1))
	{
		int z = str[i]-'a'+1;
		if(!trie[p][z])
			trie[p][z] = ++tot;
		p = trie[p][z];
	}
	match[x] = p+1;
}
void build()
{
	queue<int> q;
	rep(i, 1, 26)
		if(trie[0][i])
			q.push(trie[0][i]);
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
		edge[fail[i]+1].pb(i+1);
}
void AC(char str[])
{
	int p = 0;
	k = 0;
	rep(i, 1, strlen(str+1))
	{
		int z = str[i]-'a'+1;
		p = trie[p][z];
		node[++k] = p+1;
	}
	sort(node+1, node+1+k, cmp);
	k = unique(node+1, node+1+k)-node-1;
	rep(i, 1, k-1)
	{
		update(dfn[node[i]], 1);
		update(dfn[lca(node[i], node[i+1])], -1);
	}
	update(dfn[node[k]], 1);
}
int main()
{
	scanf("%d", &n);
	rep(i, 1, n)
	{
		scanf("%s", s+1);
		insert(i, s);
	}
	build();
	dfs1(1, 0);
	dfs2(1, 1);
	scanf("%d", &q);
	rep(i, 1, q)
	{
		int op, x;
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%s", s+1);
			AC(s);
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", query(dfn[match[x]]+siz[match[x]]-1)-query(dfn[match[x]]-1));
		}
	}
	return 0;
}