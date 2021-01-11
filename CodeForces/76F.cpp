#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
using namespace std;
namespace IO
{
	char buf[1<<23], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
	#define isdigit(c) (c >= 48 && c <= 57)
	#define isalpha(c) ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	template<typename T> inline void read(T &x)
	{
		x = 0;
		register int f = 1;
		register char ch = getchar();
		while(!isdigit(ch))
		{
			if(ch == 45)
				f = -1;
			ch = getchar();
		}
		while(isdigit(ch))
		{
			x = (x<<1)+(x<<3)+(ch^48);
			ch = getchar();
		}
		x *= f;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
typedef long long ll;
const int N = 1e5+10, inf = 0x3f3f3f3f;
struct Event
{
	int p;
	int q;
	int id;
	bool operator < (const Event &x) const
	{
		return p == x.p ? q < x.q : p < x.p;
	}
};
Event a[N], b[N];
int n, v, qwq, ans, c[N], tree[N], dp[N];
void update(int x, int k)
{
	for(; x <= qwq; x += lowbit(x))
		tree[x] = max(tree[x], k);
}
int query(int x)
{
	int ans = 0;
	for(; x >= 1; x -= lowbit(x))
		ans = max(ans, tree[x]);
	return ans;
}
int main()
{
	read(n);
	rep(i, 1, n)
		read(a[i].p, a[i].q);
	read(v);
	rep(i, 1, n)
	{
		b[i] = (Event){-v*a[i].q+a[i].p, -v*a[i].q-a[i].p, i};
		c[i] = b[i].q;
	}
	sort(c+1, c+2+n);
	qwq = unique(c+1, c+2+n)-c-1;
	rep(i, 1, n+1)
		b[i].q = lower_bound(c+1, c+1+qwq, b[i].q)-c;
	sort(b+1, b+2+n);
	rep(i, 1, n+1)
	{
		dp[i] = query(b[i].q)+1;
		update(b[i].q, dp[i]);
		if(a[b[i].id].q == 0)
			printf("%d ",dp[i]-1);
		else
			ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}