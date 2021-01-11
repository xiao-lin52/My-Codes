#include <bits/stdc++.h>
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
const int N = 2e5+10, inf = 0x3f3f3f3f, mod = 1e9;
struct Matrix
{
	int h, l;
	ll mat[3][3];
	void init()
	{
		memset(mat, 0, sizeof(mat));
	}
	Matrix operator * (Matrix const &b) const
	{
		Matrix res;
		res.init();
		res.h = h;
		res.l = b.l;
		rep(i, 1, h)
			rep(k, 1, l)
			{
				ll t = mat[i][k];
				rep(j, 1, b.l)
					res.mat[i][j] = (res.mat[i][j]+b.mat[k][j]*t%mod)%mod;
			}
		return res;
	}
	Matrix operator * (int const &b) const
	{
		Matrix res;
		res.init();
		res.h = h;
		res.l = l;
		rep(i, 1, h)
			rep(j, 1, l)
				res.mat[i][j] = mat[i][j]*b%mod;
		return res;
	}
	Matrix operator + (Matrix const &b) const
	{
		Matrix res;
		res.init();
		res.h = h;
		res.l = l;
		rep(i, 1, h)
			rep(j, 1, l)
				res.mat[i][j] = (mat[i][j]+b.mat[i][j])%mod;
		return res;
	}
};
struct SegTree
{
	int l;
	int r;
	int tag;
	Matrix qwq;
	Matrix data;
};
Matrix f[N];
SegTree tree[N<<2];
int n, m, a[N], fib[N];
inline void push_down(int p)
{
	if(!tree[p].tag)
		return;
	tree[p<<1].data = tree[p<<1].data+tree[p<<1].qwq*tree[p].tag;
	tree[p<<1|1].data = tree[p<<1|1].data+tree[p<<1|1].qwq*tree[p].tag;
	tree[p<<1].tag = (tree[p<<1].tag+tree[p].tag)%mod;
	tree[p<<1|1].tag = (tree[p<<1|1].tag+tree[p].tag)%mod;
	tree[p].tag = 0;
}
inline void push_up(int p)
{
	tree[p].qwq = tree[p<<1].qwq+tree[p<<1|1].qwq;
	tree[p].data = tree[p<<1].data+tree[p<<1|1].data;
}
void build(int p, int l, int r)
{
	tree[p].l = l;
	tree[p].r = r;
	if(l == r)
	{
		tree[p].qwq.h = tree[p].data.h = 1;
		tree[p].qwq.l = tree[p].data.l = 2;
		tree[p].qwq.mat[1][1] = fib[l-1];
		tree[p].qwq.mat[1][2] = fib[l];
		tree[p].data = tree[p].qwq*a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
	push_up(p);
}
void update(int p, int x, int y, int k, int op)
{
	if(x <= tree[p].l && tree[p].r <= y)
	{
		if(op == 3)
		{
			tree[p].data = tree[p].data+tree[p].qwq*k;
			tree[p].tag = (tree[p].tag+k)%mod;
		}
		else
			tree[p].data = tree[p].qwq*k;
		return;
	}
	push_down(p);
	if(tree[p<<1].r >= x)
		update(p<<1, x, y, k, op);
	if(tree[p<<1|1].l <= y)
		update(p<<1|1, x, y, k, op);
	push_up(p);
}
Matrix query(int p, int x, int y)
{
	if(x <= tree[p].l && tree[p].r <= y)
		return tree[p].data*f[x-1];
	push_down(p);
	Matrix ans;
	ans.init();
	ans.h = 1;
	ans.l = 2;
	if(tree[p<<1].r >= x)
		ans = ans+query(p<<1, x, y);
	if(tree[p<<1|1].l <= y)
		ans = ans+query(p<<1|1, x, y);
	return ans;
}
int main()
{
	read(n, m);
	rep(i, 1, n)
		read(a[i]);
	fib[1] = 1;
	f[1].h = f[1].l = f[0].h = f[0].l = 2;
	f[1].mat[1][2] = f[1].mat[2][1] = 1;
	f[1].mat[1][1] = mod-1;
	f[0].mat[1][1] = f[0].mat[2][2] = 1;
	rep(i, 2, n)
	{
		f[i] = f[i-1]*f[1];
		fib[i] = (fib[i-1]+fib[i-2])%mod;
	}
	build(1, 1, n);
	rep(i, 1, m)
	{
		int op, l, r, k;
		read(op, l, r);
		if(op == 1)
		{
			update(1, l, l, r, op);
			a[l] = r;
		}
		else if(op == 2)
		{
			Matrix ans = query(1, l, r);
			printf("%lld\n", ans.mat[1][2]);
		}
		else
		{
			read(k);
			update(1, l, r, k, op);
		}
	}
	return 0;
}