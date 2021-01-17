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
	inline void reads(char x[])
	{
		register int cnt = 1;
		register char ch = getchar();
		while(isspace(ch))
			ch = getchar();
		while(!isspace(ch))
		{
			x[cnt] = ch;
			cnt++;
			ch = getchar();
		}
	}
	inline void readc(char &x)
	{
		register char ch = getchar();
		while(isspace(ch))
			ch = getchar();
		x = ch;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
typedef long long ll;
const int N = 2e5+10, inf = 0x3f3f3f3f;
struct ALTXDY
{
	ll dis1;//left-up->right-up
	ll dis2;//left-up->right-down
	ll dis3;//left-down->right-down
	ll dis4;//left-down->right-up
	ALTXDY()
	{
		dis1 = dis2 = dis3 = dis4 = inf;
	}
};
struct SegTree
{
	int l, r;
	ALTXDY data;
};
SegTree tree[N<<2];
int n, m;
char a[2][N];
inline void merge(ALTXDY &dist, ALTXDY a, ALTXDY b)
{
	dist.dis1 = min(a.dis1+b.dis1, a.dis2+b.dis4)+1;
	dist.dis2 = min(a.dis1+b.dis2, a.dis2+b.dis3)+1;
	dist.dis3 = min(a.dis3+b.dis3, a.dis4+b.dis2)+1;
	dist.dis4 = min(a.dis3+b.dis4, a.dis4+b.dis1)+1;
}
void build(int p, int l, int r)
{
	tree[p].l = l;
	tree[p].r = r;
	if(l == r)
	{
		if(a[0][l] == '.')
		{
			tree[p].data.dis1 = 0;
			if(a[1][l] == '.')
				tree[p].data.dis2 = 1;
		}
		if(a[1][l] == '.')
		{
			tree[p].data.dis3 = 0;
			if(a[0][l] == '.')
				tree[p].data.dis4 = 1;
		}
		return;
	}
	int mid = (l+r)>>1;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
	merge(tree[p].data, tree[p<<1].data, tree[p<<1|1].data);
}
ALTXDY query(int p, int x, int y)
{
	if(tree[p].l >= x && tree[p].r <= y)
		return tree[p].data;
	ALTXDY ans;
	if(tree[p<<1].r >= x)
	{
		ans = query(p<<1, x, y);
		if(tree[p<<1|1].l <= y)
			merge(ans, ans, query(p<<1|1, x, y));
	}
	else
		if(tree[p<<1|1].l <= y)
			ans = query(p<<1|1, x, y);
	return ans;
}
int main()
{
	read(n, m);
	reads(a[0]);
	reads(a[1]);
	build(1, 1, n);
	rep(i, 1, m)
	{
		int u, v;
		read(u, v);
		if((u-1)%n+1 > (v-1)%n+1)
			swap(u, v);
		ALTXDY ans = query(1, (u-1)%n+1, (v-1)%n+1);
		if(u <= n && v <= n)
			printf("%d\n", ans.dis1 > 2*n ? -1 : ans.dis1);
		else if(u <= n && v > n)
			printf("%d\n", ans.dis2 > 2*n ? -1 : ans.dis2);
		else if(u > n && v > n)
			printf("%d\n", ans.dis3 > 2*n ? -1 : ans.dis3);
		else
			printf("%d\n", ans.dis4 > 2*n ? -1 : ans.dis4);
	}
	return 0;
}