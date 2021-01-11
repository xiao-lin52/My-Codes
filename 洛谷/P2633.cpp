#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10, inf = 0x3f3f3f3f;
struct SegTree
{
	int ls;
	int rs;
	int dat;
};
SegTree tree[N*40];
int n, m, tot, lastans, qwq, c[N], fa[N][30], dep[N], a[N], rt[N];
vector<int> edge[N];
void update(int &i, int j, int l, int r, int x)
{
	i = ++tot;
	tree[i] = tree[j];
	tree[i].dat++;
	if(l == r)
		return;
	int mid = (l+r)>>1;
	if(x <= mid)
		update(tree[i].ls, tree[j].ls, l, mid, x);
	else
		update(tree[i].rs, tree[j].rs, mid+1, r, x);
}
int query(int p1, int p2, int p3, int p4, int l, int r, int k)
{
	if(l == r)
		return l;
	int mid = (l+r)>>1;
	int t = (tree[tree[p1].ls].dat+tree[tree[p2].ls].dat)-(tree[tree[p3].ls].dat+tree[tree[p4].ls].dat);
	if(t >= k)
		return query(tree[p1].ls, tree[p2].ls, tree[p3].ls, tree[p4].ls, l, mid, k);
	else
		return query(tree[p1].rs, tree[p2].rs, tree[p3].rs, tree[p4].rs, mid+1, r, k-t);
}
void dfs(int u, int f)
{
	fa[u][0] = f;
	dep[u] = dep[f]+1;
	update(rt[u], rt[f], 1, qwq, a[u]);
	for(int i = 1; (1<<i) <= dep[u]; i++)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i = 0; i < edge[u].size(); i++)
		if(edge[u][i] != f)
			dfs(edge[u][i], u);
}
int lca(int u, int v)
{
	if(dep[u] < dep[v])
		swap(u, v);
	int depu = dep[u], depv = dep[v];
	for(int i = 0 ; (1<<i) <= depu-depv; i++)
		if((1<<i)&(depu-depv))
			u = fa[u][i];
	if(u == v)
		return u;
	for(int i = 20; i >= 0; i--)
		if(fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	return fa[u][0];
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	sort(c+1, c+1+n);
	qwq = unique(c+1, c+1+n)-c-1;
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(c+1, c+1+qwq, a[i])-c;
	for(int i = 1; i <= n-1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= m; i++)
	{
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		u ^= lastans;
		int LCA = lca(u, v);
		printf("%d\n", lastans = c[query(rt[u], rt[v], rt[LCA], rt[fa[LCA][0]], 1, qwq, k)]);
	}
	return 0;
}