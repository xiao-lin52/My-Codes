#include <bits/stdc++.h>
#define rep(i, l, r) for(register int i = (l), i##end = (r); i <= i##end; i++)
namespace IN
{
	char buf[1<<24], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, 1<<23, stdin), p1 == p2) ? EOF : *p1++)
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
}
namespace OUT
{
	char buf[1<<24],a[20];int p,p2=-1;
	inline void flush()
	{
		fwrite(buf, 1, p2+1, stdout), p2=-1;
	}
	inline void print(int x)
	{
		if(p2 > 1<<23)
			flush();
		do
		{
			a[++p] = x%10+48;
		}while(x /= 10);
		do
		{
			buf[++p2] = a[p];
		}while(--p);
		buf[++p2] = '\n';
	}
}
typedef long long ll;
const int N = 2e5+10, B = 5e3+10, mod = 1e9+7;
int n, m, len, num, belong[N], l[B], r[B];
ll a[N], sum[B];
char p[B];
struct BIT
{
	#define lowbit(x) (x&(-x))
	ll tree[B];
	inline void update(int x, ll k)
	{
		for(; x <= len; x++)
			tree[x] = (tree[x]+k)%mod;
	}
	inline ll query(int l, int r)
	{
		return ((tree[r]-tree[l-1])%mod+mod)%mod;
	}
};
BIT tag[B];
inline void update(int x, int y, ll z)
{
	if(x >= len)
	{
		int i = y;
		for(; i+7*x <= n; i += 8*x)
		{
			a[i] = (a[i]+z)%mod, sum[belong[i]] = (sum[belong[i]]+z)%mod;
			a[i+x*1] = (a[i+x*1]+z)%mod, sum[belong[i+x*1]] = (sum[belong[i+x*1]]+z)%mod;
			a[i+x*2] = (a[i+x*2]+z)%mod, sum[belong[i+x*2]] = (sum[belong[i+x*2]]+z)%mod;
			a[i+x*3] = (a[i+x*3]+z)%mod, sum[belong[i+x*3]] = (sum[belong[i+x*3]]+z)%mod;
			a[i+x*4] = (a[i+x*4]+z)%mod, sum[belong[i+x*4]] = (sum[belong[i+x*4]]+z)%mod;
			a[i+x*5] = (a[i+x*5]+z)%mod, sum[belong[i+x*5]] = (sum[belong[i+x*5]]+z)%mod;
			a[i+x*6] = (a[i+x*6]+z)%mod, sum[belong[i+x*6]] = (sum[belong[i+x*6]]+z)%mod;
			a[i+x*7] = (a[i+x*7]+z)%mod, sum[belong[i+x*7]] = (sum[belong[i+x*7]]+z)%mod;
		}
		for(; i <= n; i += x)
			a[i] = (a[i]+z)%mod, sum[belong[i]] = (sum[belong[i]]+z)%mod;
	}
	else
		tag[x].update(y, z), p[x] = 1;
}
inline ll query(int x, int y)
{
	ll res = 0;
	rep(i, belong[x]+1, belong[y]-1)
		res = (res+sum[i])%mod;
	rep(i, 1, len-1)
		if(p[i])
		{
			int t1 = (x-1)%i+1, t2 = (y-1)%i+1, t3 = (y-1)/i+1, t4 = (x-1)/i+1;
			res = t3 == t4 ? (res+tag[i].query(t1, t2))%mod : (res+tag[i].query(1, t2)+tag[i].query(t1, len)+tag[i].query(1, len)*(t3-t4-1)%mod)%mod;
		}
	if(belong[x] == belong[y])
		rep(i, x, y)
			res = (res+a[i])%mod;
	else
	{
		register int i;
		for(i = l[belong[y]]; i+7 <= y; i += 8)
			res = (res+a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7])%mod;
		for(; i <= y; i++)
			res = (res+a[i])%mod;
		for(i = x; i+7 <= r[belong[x]]; i += 8)
			res = (res+a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7])%mod;
		for(; i <= r[belong[x]]; i++)
			res = (res+a[i])%mod;
	}
	return res;
}
int main()
{
	IN::read(n);
	IN::read(m);
	len = 180;
	num = (n-1)/len+1;
	for(register int i = 1; i+7 <= n; i += 8)
	{
		IN::read(a[i]);
		belong[i] = (i-1)/len+1;
		sum[belong[i]] = (sum[belong[i]]+a[i])%mod;
		IN::read(a[i+1]);
		belong[i+1] = (i+1-1)/len+1;
		sum[belong[i+1]] = (sum[belong[i+1]]+a[i+1])%mod;
		IN::read(a[i+2]);
		belong[i+2] = (i+2-1)/len+1;
		sum[belong[i+2]] = (sum[belong[i+2]]+a[i+2])%mod;
		IN::read(a[i+3]);
		belong[i+3] = (i+3-1)/len+1;
		sum[belong[i+3]] = (sum[belong[i+3]]+a[i+3])%mod;
		IN::read(a[i+4]);
		belong[i+4] = (i+4-1)/len+1;
		sum[belong[i+4]] = (sum[belong[i+4]]+a[i+4])%mod;
		IN::read(a[i+5]);
		belong[i+5] = (i+5-1)/len+1;
		sum[belong[i+5]] = (sum[belong[i+5]]+a[i+5])%mod;
		IN::read(a[i+6]);
		belong[i+6] = (i+6-1)/len+1;
		sum[belong[i+6]] = (sum[belong[i+6]]+a[i+6])%mod;
		IN::read(a[i+7]);
		belong[i+7] = (i+7-1)/len+1;
		sum[belong[i+7]] = (sum[belong[i+7]]+a[i+7])%mod;
	}
	for(register int i = n/8*8+1; i <= n; i++)
	{
		IN::read(a[i]);
		belong[i] = (i-1)/len+1;
		sum[belong[i]] = (sum[belong[i]]+a[i])%mod;
	}
	for(register int i = 1; i+7 <= num-1; i += 8)
	{
		l[i] = r[i-1]+1;
		r[i] = i*len;
		l[i+1] = r[i+1-1]+1;
		r[i+1] = (i+1)*len;
		l[i+2] = r[i+2-1]+1;
		r[i+2] = (i+2)*len;
		l[i+3] = r[i+3-1]+1;
		r[i+3] = (i+3)*len;
		l[i+4] = r[i+4-1]+1;
		r[i+4] = (i+4)*len;
		l[i+5] = r[i+5-1]+1;
		r[i+5] = (i+5)*len;
		l[i+6] = r[i+6-1]+1;
		r[i+6] = (i+6)*len;
		l[i+7] = r[i+7-1]+1;
		r[i+7] = (i+7)*len;
	}
	for(register int i = (num-1)/8*8+1; i <= num-1; i++)
	{
		l[i] = r[i-1]+1;
		r[i] = i*len;
	}
	l[num] = r[num-1]+1;
	r[num] = n;
	rep(i, 1, m)
	{
		int op, x, y, z;
		IN::read(op);
		IN::read(x);
		IN::read(y);
		if(op == 1)
		{
			IN::read(z);
			update(x, y, z);
		}
		else
			OUT::print(query(x, y));
	}
	OUT::flush();
	return 0;
}