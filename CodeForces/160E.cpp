#include <bits/stdc++.h>
using namespace std;
namespace IO
{
	char buf[1<<22], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, 1<<21, stdin), p1==p2) ? EOF : *p1++)
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
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
struct ALTXDY
{
	int tp, t, x, y, id;
	bool operator < (ALTXDY const &a) const
	{
		return x == a.x ? tp < a.tp : x < a.x;
	}
};
ALTXDY q[N<<1];
int n, m, tot, bus[N], ans[N], c[N<<1], dat[N<<2], ls[N<<2], rs[N<<2];
void update(int &i, int l, int r, int x, int k)
{
	if(!i)
		i=++tot;
	if(bus[dat[i]] < bus[k])
		dat[i] = k;
	if(l == r)
		return;
	int mid = (l+r)>>1;
	if(x <= mid)
		update(ls[i], l, mid, x, k);
	else
		update(rs[i], mid+1, r, x, k);
}
int query(int i, int l, int r, int x, int y, int val)
{
	if(l == r)
		return dat[i];
	int mid = (l+r)>>1, t = -1;
	if(x <= mid && ls[i] && bus[dat[ls[i]]] >= val)
		t = query(ls[i], l, mid, x, y, val);
	if(t == -1 && y >= mid+1 && rs[i] && bus[dat[rs[i]]] >= val)
		t = query(rs[i], mid+1, r, x, y, val);
	return t;
}
int main()
{
	read(n, m);
	for(int i = 1; i <= n; i++)
	{
		int s, f, t;
		read(s, f, t);
		q[i] = (ALTXDY){0, t, s, f, i};
		c[i] = t;
		bus[i] = f;
	}
	for(int i = 1; i <= m; i++)
	{
		int b, l, r;
		read(l, r, b);
		q[i+n] = (ALTXDY){1, b, l, r, i};
		c[i+n] = b;
	}
	sort(c+1, c+1+n+m);
	register int k = unique(c+1, c+1+n+m)-c-1;
	for(int i = 1; i <= n+m; i++)
		q[i].t = lower_bound(c+1, c+1+k, q[i].t)-c;
	sort(q+1, q+1+n+m);
	register int rt = 0;
	for(int i = 1; i <= n+m; i++)
		if(q[i].tp == 0)
			update(rt, 1, k, q[i].t, q[i].id);
		else
			ans[q[i].id] = query(rt, 1, k, q[i].t, k, q[i].y);
	for(int i =1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
}