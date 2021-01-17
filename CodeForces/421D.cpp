#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lowbit(x) (x&(-x))
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
const int N = 3e5+10;
int n, m, rt, tot, sum[N], tree[N];
ll ans;
pii b[N];
void update(int x)
{
	for(; x <= n+1; x += lowbit(x))
		tree[x]++;
}
int query(int x)
{
	int res = 0;
	for(; x >= 1; x -= lowbit(x))
		res += tree[x];
	return res;
}
int main()
{
	read(n, m);
	rep(i, 1, n)
	{
		int x, y;
		read(x, y);
		sum[x]++;
		sum[y]++;
		if(x > y)
			swap(x, y);
		b[i] = mp(x, y);
	}
	sort(b+1, b+1+n);
	rep(i, 1, n)
		update(sum[i]+1);
	rep(i, 1, n)
	{
		ans += query(n+1)-query(max(0, m-sum[i]));
		if(m-sum[i] <= sum[i])
			ans--;
	}
	int tmp = 0;
	rep(i, 1, n)
	{
		tmp++;
		if(i == n || b[i+1] != b[i])
		{
			if(sum[b[i].fi]+sum[b[i].se] >= m && sum[b[i].fi]+sum[b[i].se]-tmp < m)
				ans -= 2;
			tmp = 0;
		}
	}
	printf("%lld", ans/2);
	return 0;
}