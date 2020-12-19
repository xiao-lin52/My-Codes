#include <bits/stdc++.h>
#define pii pair<int, ll>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
struct Trie
{
	int tot, son[N * 50][2];
	void insert(ll x)
	{
		int p = 0;
		for (int i = 31; i >= 0; i--)
		{
			int s = (x >> i) & 1;
			if (!son[p][s])
				son[p][s] = ++tot;
			p = son[p][s];
		}
	}
	ll query(ll x)
	{
		int p = 0;
		ll ans = 0;
		for (int i = 31; i >= 0; i--)
		{
			int s = (x >> i) & 1;
			if (son[p][s ^ 1])
			{
				p = son[p][s ^ 1];
				ans += 1ll << i;
			}
			else
				p = son[p][s];
		}
		return ans;
	}
};
Trie trie;
ll n, ans;
vector<pii> edge[N];
void dfs(int u, int fa, ll sum)
{
	ans = max(ans, trie.query(sum));
	trie.insert(sum);
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i].first;
		ll c = edge[u][i].second;
		if (v != fa)
			dfs(v, u, sum ^ c);
	}
}
int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n - 1; i++)
	{
		ll u, v, c;
		scanf("%lld%lld%lld", &u, &v, &c);
		edge[u].push_back(mp(v, c));
		edge[v].push_back(mp(u, c));
	}
	dfs(1, 0, 0);
	printf("%lld", ans);
	return 0;
}