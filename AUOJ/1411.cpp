#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define debug(x) cerr<<#x<<" = "<<x
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
		register int f=1;
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
typedef long long ll;
const int N = 5e3+10, inf = 0x3f3f3f3f;
int n, q, ms, tot, w[N], a[N], siz[N], son[N], dfn[N], rk[N], x[N*20], s[N*20];
ll dp[N][N];
vector<int> edge[N];
void dfs1(int u, int f)
{
	siz[u] = 1;
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		if(v != f)
		{
			dfs1(v, u);
			son[u] = siz[son[u]] > siz[v] ? son[u] : v;
			siz[u] += siz[v];
		}
	}
}
void dfs2(int u, int f)
{
	tot++;
	dfn[u] = tot;
	rk[tot] = u;
	if(son[u])
		dfs2(son[u], u);
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		if(v != f && v != son[u])
			dfs2(v, u);
	}
}
void dfs(int u, int f)
{
	if(son[u])
		dfs(son[u], u);
	rep(i, 0, ms)
		if(i >= a[u])
			dp[u][i] = max(dp[son[u]][i], dp[son[u]][i-a[u]]+w[u]);
		else
			dp[u][i] = dp[son[u]][i];
	rep(i, 0, edge[u].size()-1)
	{
		int v = edge[u][i];
		if(v != f && v != son[u])
			dfs(v, u);
	}
	if(son[u])
		rep(i, dfn[son[u]]+siz[son[u]], dfn[u]+siz[u]-1)
			per(j, ms, a[rk[i]])
				dp[u][j] = max(dp[u][j], dp[u][j-a[rk[i]]]+w[rk[i]]);
}
int main()
{
	read(n);
	rep(i, 1, n-1)
	{
		int u, v;
		read(u, v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	rep(i, 1, n)
		read(w[i], a[i]);
	read(q);
	rep(i, 1, q)
	{
		read(x[i], s[i]);
		ms = max(ms, s[i]);
	}
	dfs(1, 0);
	rep(i, 1, q)
		printf("%lld\n", dp[x[i]][s[i]]);
	return 0;
}