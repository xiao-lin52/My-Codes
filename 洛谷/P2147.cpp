#include <bits/stdc++.h>
#define get(x) (son[fa[x]][1] == x)
#define isRoot(x) (son[fa[x]][0] != x && son[fa[x]][1] != x)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, inf = INT_MAX;
int n, m, son[N][2], fa[N], tag[N], st[N];
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
}
inline void update(int p)
{
	int j = p, top = 0;
	while(!isRoot(j))
		j = st[++top] = fa[j];
	while(top)
		push_down(st[top--]);
	push_down(p);
}
inline void splay(int p)
{
	update(p);
	for(int f; f = fa[p], !isRoot(p); spin(p))
		if(!isRoot(f))
			spin(get(f) == get(p) ? f : p);
}
inline void access(int p)
{
	for(int t = 0; p; t = p, p = fa[p])
	{
		splay(p);
		son[p][1] = t;
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
	make_root(u);
	splay(v);
	fa[u] = v;
}
inline void cut(int u, int v)
{
	split(u, v);
	fa[u] = son[v][0] = 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	while(m--)
	{
		char op[10];
		int x, y;
		scanf("%s%d%d", op, &x, &y);
		if(op[0] == 'Q')
			printf("%s\n", find_root(x) == find_root(y) ? "Yes" : "No");
		else if(op[0] == 'D')
			cut(x, y);
		else
			link(x, y);
	}
	return 0;
}