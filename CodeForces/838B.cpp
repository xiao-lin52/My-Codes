#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
typedef long long ll;
using namespace std;
namespace IO
{
	char buf[1<<23],*p1=buf,*p2=buf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	#define isdigit(c) (c>=48&&c<=57)
	#define isalpha(c) ((c>=65&&c<=90)||(c>=97&&c<=122))
	template<typename T> inline void read(T &x)
	{
		x=0;
		register char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
const ll N = 2e5 + 10, inf = 1e18;
struct SegTree
{
	ll l[N<<2], r[N<<2];
	ll mn[N<<2], tag[N<<2];
	inline void push_up(ll i)
	{
		mn[i] = min(mn[i<<1], mn[i<<1|1]);
	}
	inline void push_down(ll i)
	{
		mn[i<<1] += tag[i];
		mn[i<<1|1] += tag[i];
		tag[i<<1] += tag[i];
		tag[i<<1|1] += tag[i];
		tag[i] = 0;
	}
	void build(ll i, ll x, ll y)
	{
		l[i] = x;
		r[i] = y;
		if(x == y)
			return;
		build(i<<1, x, (x+y)>>1);
		build(i<<1|1, ((x+y)>>1)+1, y);
	}
	void update(ll i, ll x, ll y, ll k)
	{
		if(l[i] >= x && r[i] <= y)
		{
			mn[i] += k;
			tag[i] += k;
			return;
		}
		push_down(i);
		if(r[i<<1] >= x)
			update(i<<1, x, y, k);
		if(l[i<<1|1] <= y)
			update(i<<1|1, x, y, k);
		push_up(i);
	}
	ll query(ll i, ll x, ll y)
	{
		if(l[i] >= x && r[i] <= y)
			return mn[i];
		push_down(i);
		ll ans = inf;
		if(r[i<<1] >= x)
			ans = min(ans, query(i<<1, x, y));
		if(l[i<<1|1] <= y)
			ans = min(ans, query(i<<1|1, x, y));
		push_up(i);
		return ans;
	}
};
SegTree dis1, dis2;
ll n, m, cnt, u[N<<2], v[N<<2], c[N<<2], f[N], dfn[N], siz[N], dep[N];
vector<pii> edge[N];
ll dfs(ll u, ll sum, ll depth)
{
	cnt++;
	dep[u] = depth;
	dfn[u] = cnt;
	siz[u] = 1;
	dis1.update(1, dfn[u], dfn[u], sum);
	dis2.update(1, dfn[u], dfn[u], sum+f[u]);
	for(ll i = 0; i < edge[u].size(); i++)
		siz[u] += dfs(edge[u][i].first, sum+edge[u][i].second, dep[u]+1);
	return siz[u];
}
int main()
{
	read(n, m);
	dis1.build(1, 1, n);
	dis2.build(1, 1, n);
	for(ll i = 1; i <= n-1; i++)
	{
		read(u[i], v[i], c[i]);
		edge[u[i]].push_back(mp(v[i], c[i]));
	}
	for(ll i = n; i <= 2*n-2; i++)
	{
		read(u[i], v[i], c[i]);
		f[u[i]] = c[i];
	}
	dfs(1ll, 0ll, 1ll);
	while(m--)
	{
		ll op, x, y;
		read(op, x, y);
		if(op==1)
			if(x <= n-1)
			{
				dis1.update(1ll, dfn[v[x]], dfn[v[x]]+siz[v[x]]-1, y-c[x]);
				dis2.update(1ll, dfn[v[x]], dfn[v[x]]+siz[v[x]]-1, y-c[x]);
				c[x] = y;
			}
			else
			{
				dis2.update(1ll, dfn[u[x]], dfn[u[x]], y-f[u[x]]);
				f[u[x]] = y;
			}
		else
			if(dfn[x] <= dfn[y] && dfn[x]+siz[x]-1 >= dfn[y])
				printf("%lld\n", dis1.query(1ll, dfn[y], dfn[y])-dis1.query(1ll, dfn[x], dfn[x]));
			else
				printf("%lld\n", dis2.query(1ll, dfn[x], dfn[x]+siz[x]-1)-dis1.query(1ll, dfn[x], dfn[x])+dis1.query(1ll, dfn[y], dfn[y]));
	}
	return 0;
}