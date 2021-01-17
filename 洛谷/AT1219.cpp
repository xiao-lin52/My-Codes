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
namespace IO
{
	char buf[1<<23], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
	#define isdigit(c) (c >= 48 && c <= 57)
	#define isalpha(c) ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	template<typename T> inline void read(T &x)
	{
		x = 0;
		register char ch = getchar();
		while(!isdigit(ch))
			ch = getchar();
		while(isdigit(ch))
		{
			x = (x<<1)+(x<<3)+(ch^48);
			ch = getchar();
		}
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
typedef long long ll;
const int N = 1e5+10, inf = 0x3f3f3f3f;
int n, m, len, a[N], c[N], belong[N], lt[N], rt[N], cnt[N];
ll num, ans[N];
struct Query
{
	int x;
	int y;
	int id;
	bool operator < (const Query &b) const
	{
		return belong[x]^belong[b.x] ? belong[x] < belong[b.x] : y < b.y;
	}
};
Query q[N];
inline void add(int x)
{
	num = max(num, 1ll*(++cnt[a[x]])*c[a[x]]);
}
int main()
{
	read(n, m);
	len = sqrt(n);
	rep(i, 1, n)
	{
		read(a[i]);
		c[i] = a[i];
		belong[i] = (i-1)/len+1;
	}
	sort(c+1, c+1+n);
	int qwq = unique(c+1, c+1+n)-c-1;
	rep(i, 1, n)
		a[i] = lower_bound(c+1, c+1+qwq, a[i])-c;
	rep(i, 1, (n-1)/len+1)
	{
		lt[i] = rt[i-1]+1;
		rt[i] = min(i*len, n);
	}
	rep(i, 1, m)
	{
		read(q[i].x, q[i].y);
		q[i].id = i;
		if(belong[q[i].x] == belong[q[i].y])
		{
			num = 0;
			rep(j, q[i].x, q[i].y)
				add(j);
			rep(j, q[i].x, q[i].y)
				cnt[a[j]]--;
			ans[i] = num;
		}
	}
	sort(q+1, q+1+m);
	int l = 1, r = 0, lst = 0;
	rep(i, 1, m)
	{
		if(belong[q[i].x] == belong[q[i].y])
			continue;
		if(belong[q[i].x] != belong[lst])
		{
			num = 0;
			memset(cnt, 0, sizeof(cnt));
			l = rt[belong[q[i].x]]+1;
			r = l-1;
		}
		lst = q[i].x;
		while(r < q[i].y) add(++r);
		ll tmp = num;
		while(l > q[i].x) add(--l);
		ans[q[i].id] = num;
		while(l < rt[belong[q[i].x]]+1)
			--cnt[a[l++]];
		num = tmp;
	}
	rep(i, 1, m)
		printf("%lld\n", ans[i]);
	return 0;
}