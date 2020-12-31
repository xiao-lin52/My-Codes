#include <bits/stdc++.h>
#define get(p) (son[fa[p]][1] == p)
#define isRoot(p) (son[fa[p]][0] != p && son[fa[p]][1] != p)
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, inf = INT_MAX;
int n, m, a[N], son[N][2], fa[N], tag[N], siz[N], st[N];
inline void push_up(int p)
{
	siz[p] = siz[son[p][0]]+siz[son[p][1]]+1;
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
	int x = fa[p], y = fa[x], s = get(p), t = get(x);
	if(!isRoot(x))
		son[y][t] = p;
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
inline void make_root(int p)
{
	access(p);
	splay(p);
	tag[p] ^= 1;
}
inline int find_root(int p)
{
	access(p);
	splay(p);
	while(son[p][0])
		p = son[p][0];
	return p;
}
inline void split(int u, int v)
{
	make_root(u);
	access(v);
	splay(v);
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
	son[v][0] = fa[u] = 0;
}
inline int query(int u)
{
	make_root(u);
	access(n+1);
	splay(n+1);
	return siz[n+1];
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		siz[i] = 1;
		scanf("%d", &a[i]);
		if(i+a[i] <= n)
			link(i, i+a[i]);
		else
			link(i, n+1);
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int op, x, y;
		scanf("%d%d", &op, &x);
		x += 1;
		if(op == 1)
			printf("%d\n", query(x)-1);
		else
		{
			scanf("%d", &y);
			if(x+a[x] <= n)
				cut(x, x+a[x]);
			else
				cut(x, n+1);
			if(x+y <= n)
				link(x, x+y);
			else
				link(x, n+1);
			a[x] = y;
		}
	}
	return 0;
}