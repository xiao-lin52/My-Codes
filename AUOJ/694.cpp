#include <bits/stdc++.h>
#define get(x) (find(son[find(fa[x])][1]) == find(x))
#define isRoot(x) (find(son[find(fa[x])][0]) != find(x) && find(son[find(fa[x])][1]) != find(x))
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, inf = INT_MAX;
int n, m, p, f[N], son[N][2], fa[N], num[N], tag[N], st[N];
int find(int x)
{
	return f[x] == x ? f[x] : f[x] = find(f[x]);
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
void update(int p)
{
	p = find(p);
	int j = p, top = 0;
	while(!isRoot(j))
		st[++top] = j = find(fa[j]);
	while(top)
		push_down(st[top--]);
	push_down(p);
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
		son[p][1] = find(t);
	}
}
void makeroot(int p)
{
	p = find(p);
	access(p);
	splay(p);
	tag[p] ^= 1;
}
int findroot(int p)
{
	p = find(p);
	access(p);
	splay(p);
	while(son[p][0])
	{
		push_down(p);
		p = find(son[p][0]);
	}
	return p;
}
void split(int u, int v)
{
	u = find(u);
	v = find(v);
	makeroot(u);
	access(v);
	splay(v);
}
void dfs(int p, int rt)
{
	if(!p)
		return;
	p = find(p);
	dfs(son[p][0], rt);
	dfs(son[p][1], rt);
	if(f[find(p)] != rt)
		num[rt] += num[find(p)];
	f[find(p)] = rt;
}
void link(int u, int v)
{
	u = find(u);
	v = find(v);
	if(findroot(u) != findroot(v))
	{
		makeroot(u);
		splay(v);
		fa[u] = v;
	}
	else
	{
		split(u, v);
		dfs(v, v);
		son[v][0] = son[v][1] = 0;
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1; i <= n; i++)
	{
		f[i] = i;
		num[i] = 1;
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		link(u, v);
	}
	for(int i = 1; i <= p; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u = find(u);
		v = find(v);
		link(u, v);
		if(find(u) == find(v))
			printf("%d\n", num[find(u)]);
		else
			printf("No\n");
	}
	return 0;
}