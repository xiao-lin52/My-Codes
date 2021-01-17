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
const int N = 1e3+10, inf = 0x3f3f3f3f;
int n, m, e, ans, match[N], vis[N];
vector<int> edge[N];
int dfs(int u)
{
	rep(i, 0, edge[u].size()-1)
		
}
int main()
{
	scanf("%d%d%d", &n, &m, &e);
	rep(i, 1, e)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	return 0;
}