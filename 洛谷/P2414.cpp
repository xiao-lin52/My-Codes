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
namespace IO
{
	char buf[1<<23], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
	#define isdigit(c) (c >= 48 && c <= 57)
	#define isalpha(c) ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	template<typename T> inline void read(T &x)
	{
		x = 0;
		register int f = 1;
		register char ch = getchar();
		while(!isdigit(ch))
		{
			if(ch == 45)
				f = -1;
			ch = getchar();
		}
		while(isdigit(ch))
		{
			x = (x<<1)+(x<<3)+(ch^48);
			ch = getchar();
		}
		x *= f;
	}
	inline void reads(char x[])
	{
		register int cnt = 0;
		register char ch = getchar();
		while(!isalpha(ch))
			ch = getchar();
		while(isalpha(ch))
		{
			x[cnt] = ch;
			cnt++;
			ch = getchar();
		}
	}
}
using namespace IO;
typedef long long ll;
const int N = 1e5+10, inf = 0x3f3f3f3f;
int n = 1, m, tot, trie[N][30], fa[N], fail[N], e[N], match[N], node[N], nxt[N][30], ans[N];
int cnt, dfn[N], siz[N];
int tree[N];
char t[N];
vector<int> edge[N];
vector<pii> que[N];
bool cmp(int a, int b)
{
	return dfn[a] < dfn[b];
}
void dfsfail(int u, int f)
{
	cnt++;
	dfn[u] = cnt;
	siz[u] = 1;
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		dfsfail(v, u);
		siz[u] += siz[v];
	}
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
void insert(char str[])
{
	int p = 0, k = 0;
	rep(i, 1, strlen(str+1))
		if(str[i] == 'B')
			p = fa[p];
		else if(str[i] == 'P')
		{
			k++;
			e[p] = k;
			match[k] = p+1;
		}
		else
		{
			int z = str[i]-'a'+1;
			if(!trie[p][z])
				trie[p][z] = ++tot;
			fa[trie[p][z]] = p;
			p = trie[p][z];
		}
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
void solve(int u)
{
	update(dfn[u+1], 1);
	rep(i, 1, 26)
	{
		int v = nxt[u][i];
		if(v)
			solve(v);
	}
	if(e[u])
		rep(i, 0, que[e[u]].size()-1)
		{
			int x = match[que[e[u]][i].fi], id = que[e[u]][i].se;
			ans[id] = query(dfn[x]+siz[x]-1)-query(dfn[x]-1);
		}
	update(dfn[u+1], -1);
}
int main()
{
	reads(t+1);
	insert(t);
	memcpy(nxt, trie, sizeof(trie));
	build();
	dfsfail(1, 0);
	read(m);
	rep(i, 1, m)
	{
		int x, y;
		read(x);
		read(y);
		que[y].pb(mp(x, i));
	}
	solve(0);
	rep(i, 1, m)
		printf("%d\n", ans[i]);
	return 0;
}