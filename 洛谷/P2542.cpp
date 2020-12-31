#include <bits/stdc++.h>
#define get(x) (find(son[find(fa[x])][1]) == x)
#define isRoot(x) (find(son[find(fa[x])][0]) != x && find(son[find(fa[x])][1]) != x)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, inf = INT_MAX;
int n, m, k, tot, cnt, top, dfn[N], low[N], f[N], st[N], col[N], op[N][3];
int num, son[N][2], fa[N], tag[N], siz[N], ans[N];
vector<int> edge[N];
bitset<N> buc;
int find(int x)
{
	return f[x] == x ? f[x] : f[x] = find(f[x]);
}
void tarjan(int u,int p)
{
	tot++;
	dfn[u] = low[u] = tot;
	st[++top] = u;
	for(int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if(!dfn[v])
		{
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else
			if(v != p)
				low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u])
	{
		cnt++;
		while(st[top+1] != u)
		{
			f[find(st[top])] = u;
			col[st[top]] = cnt;
			top--;
		}
	}
}
void push_up(int p)
{
	siz[find(p)] = siz[find(son[p][0])]+siz[find(son[p][1])]+1;
}
void push_down(int p)
{
	p = find(p);
	if(!tag[p])
		return;
	tag[find(son[p][0])] ^= 1;
	tag[find(son[p][1])] ^= 1;
	swap(son[p][0], son[p][1]);
	tag[p] = 0;
}
void spin(int p)
{
	p = find(p);
	int x = find(fa[p]), y = find(fa[x]), s = get(p), t = get(x);
	if(!isRoot(x))
		son[y][t] = p;
	fa[find(son[p][s^1])] = x;
	fa[p] = y;
	fa[x] = p;
	son[x][s] = find(son[p][s^1]);
	son[p][s^1] = x;
	push_up(x);
	push_up(p);
}
void update(int p)
{
	p = find(p);
	int j = p;
	top = 0;
	while(!isRoot(j))
		st[++top] = j = find(fa[j]);
	while(top)
		push_down(st[top--]);
	push_down(p);
}
void splay(int p)
{
	p = find(p);
	update(find(p));
	for(int f; f = find(fa[p]), !isRoot(p); spin(p))
		if(!isRoot(f))
			spin(get(f) == get(p) ? f : p);
}
void access(int p)
{
	p = find(p);
	for(int t = 0; p; t = p, p = find(fa[p]))
	{
		splay(p);
		son[p][1] = t;
		push_up(p);
	}
}
void make_root(int p)
{
	p = find(p);
	access(p);
	splay(p);
	tag[p] ^= 1;
}
int find_root(int p)
{
	p = find(p);
	access(p);
	splay(p);
	while(son[p][0])
		p = find(son[p][0]);
	return p;
}
void split(int u, int v)
{
	u = find(u);
	v = find(v);
	make_root(u);
	access(v);
	splay(v);
}
void link(int u, int v)
{
	u = find(u);
	v = find(v);
	make_root(u);
	splay(v);
	fa[u] = v;
}
void dfs(int p, int rt)
{
	if(!p)
		return;
	p = find(p);
	dfs(son[p][0], rt);
	dfs(son[p][1], rt);
	f[find(p)] = rt;
}
int query(int u, int v)
{
	int ans = 0;
	u = find(u);
	v = find(v);
	split(u, v);
	return siz[find(v)]-1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
		sort(edge[i].begin(), edge[i].end());
	int tmp;
	while(scanf("%d", &tmp)&&tmp != -1)
	{
		k++;
		op[k][0] = tmp;
		scanf("%d%d", &op[k][1], &op[k][2]);
		if(tmp == 0)
		{
			edge[op[k][1]].erase(lower_bound(edge[op[k][1]].begin(), edge[op[k][1]].end(), op[k][2]));
			edge[op[k][2]].erase(lower_bound(edge[op[k][2]].begin(), edge[op[k][2]].end(), op[k][1]));
		}
	}
	tarjan(1, 0);
	for(int u = 1; u <= n; u++)
		for(int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i];
			if(col[u] != col[v] && find_root(u) != find_root(v))
				link(u, v);
		}
	while(k)
	{
		if(op[k][0] == 0)
		{
			op[k][1] = find(op[k][1]);
			op[k][2] = find(op[k][2]);
			split(op[k][1], op[k][2]);
			dfs(op[k][2], op[k][2]);
		}
		else
			ans[++num] = query(op[k][1], op[k][2]);
		k--;
	}
	for(int i = num; i >= 1; i--)
		printf("%d\n", ans[i]);
	return 0;
}