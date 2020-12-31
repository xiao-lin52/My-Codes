#include <bits/stdc++.h>
#define get(x) (son[fa[x]][1] == x)
#define isRoot(x) (son[fa[x]][0] != x && son[fa[x]][1] != x)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, inf = INT_MAX;
int n, m, a[N], son[N][2], fa[N], tag[N], siz[N], sum[N], st[N];
inline void push_up(int p)
{
	siz[p] = siz[son[p][0]]+siz[son[p][1]];
	sum[p] = sum[son[p][0]]^sum[son[p][1]]^a[p];
}
inline void push_down(int p)
{
	if(!tag[p])
		return;
	tag[son[p][0]] ^= 1;
	tag[son[p][1]] ^= 1;
	swap(son[p][0], son[p][1]);
	tag[p] = 0;
}
inline void spin(int p)
{
	int x = fa[p], y = fa[x], s = get(p), k = get(x);
	if(!isRoot(x))
		son[y][k] = p;
	fa[son[p][s^1]] = x;
	fa[p] = y;
	fa[x] = p;
	son[x][s] = son[p][s^1];
	son[p][s^1] = x;
	push_up(x);
	push_up(p);
}
inline void update(int p)
{
	int j = p, top = 0;
	while(!isRoot(j))
	{
		j = fa[j];
		push_up(j);
		st[++top] = j;
	}
	while(top)
		push_down(st[top--]);
	push_down(p);
}
inline void splay(int p)
{
	update(p);
	for(int f; f = fa[p], !isRoot(p); spin(p))
		if(!isRoot(f))
			spin(get(p) == get(f) ? f : p);
}
inline void access(int p)
{
	for(int t = 0; p; t = p, p = fa[p])
	{
		splay(p);
		son[p][1] = t;
		push_up(p);
	}
}
inline int find_root(int p)
{
	access(p);
	splay(p);
	while(son[p][0])
	{
		push_down(p);
		p = son[p][0];
	}
	push_down(p);
	splay(p);
	return p;
}
inline void make_root(int p)
{
	access(p);
	splay(p);
	tag[p] ^= 1;
}
inline void split(int u, int v)
{
	make_root(u);
	access(v);
	splay(v);
}
inline int query(int u, int v)
{
	split(u, v);
	return sum[v];
}
inline void link(int u, int v)
{
	if(find_root(u) == find_root(v))
		return;
	make_root(u);
	splay(v);
	fa[u] = v;
}
inline void cut(int u, int v)
{
	split(u, v);
	if(find_root(v) == u && son[u][1] == v && !son[v][0])
	{
		fa[v] = son[u][1] = 0;
		push_up(v);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = a[i];
	}
	while(m--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 0)
			printf("%d\n", query(x, y));
		else if(op == 1)
			link(x, y);
		else if(op == 2)
			cut(x, y);
		else
		{
			splay(x);
			sum[x] ^= a[x]^y;
			a[x] = y;
		}
	}
	return 0;
}