#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
using namespace std;
typedef long long ll;
const int N = 1e5+10, inf = 0x3f3f3f3f;
int n, rt, tot, dep[N], son[N], f[N];
vector<int> edge[N];
void dfs1(int u, int fa, int d)
{
	dep[u] = d;
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		if(v != fa)
			dfs1(v, u, d+1);
	}
	rt = dep[rt] > dep[u] ? rt : u;
}
void dfs2(int u, int fa)
{
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		if(v != fa)
			dfs2(v, u);
		son[u] = f[son[u]] > f[v] ? son[u] : v;
	}
	f[u] = f[son[u]]+1;
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		if(v != fa && v != son[u])
			tot++;
	}
}
int main()
{
	scanf("%d", &n);
	rep(i, 1, n-1)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1, 0, 1);
	dfs2(rt, 0);
	if(n == 1)
		printf("1");
	else
		printf("%d", tot+2);
	return 0;
}