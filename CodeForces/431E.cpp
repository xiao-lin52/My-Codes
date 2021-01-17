#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
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
const int N = 1e5+10, mod = 20060209;
const double inf = 1e16;
int n, m, rt, sed, tot, son[N<<1][2], siz[N<<1], num[N<<1], rnd[N<<1];
ll a[N], val[N<<1], sum[N<<1];
inline int rd()
{
	return sed = 114514ll*sed%mod*1919820%mod;
}
inline void push_up(int p)
{
	siz[p] = siz[son[p][0]]+siz[son[p][1]]+num[p];
	sum[p] = sum[son[p][0]]+sum[son[p][1]]+val[p]*num[p];
}
inline void spin(int &p, int s)
{
	int t = son[p][s];
	son[p][s] = son[t][s^1];
	son[t][s^1] = p;
	push_up(p);
	push_up(t);
	p = t;
}
void ins(int &p, ll k)
{
	if(!p)
	{
		p = ++tot;
		rnd[p] = rd();
		siz[p] = num[p] = 1;
		val[p] = sum[p] = k;
		return;
	}
	if(val[p] == k)
	{
		num[p]++;
		siz[p]++;
		sum[p] += k;
		return;
	}
	int t = (val[p] < k);
	ins(son[p][t], k);
	if(rnd[son[p][t]] > rnd[p])
		spin(p, t);
	push_up(p);
}
void del(int &p, ll k)
{
	if(!p)
		return;
	if(val[p] == k)
	{
		if(num[p] > 1)
		{
			num[p]--;
			siz[p]--;
			sum[p] -= k;
			return;
		}
		if(!son[p][0] && !son[p][1])
			p = 0;
		else if(son[p][0] && !son[p][1])
		{
			spin(p, 0);
			del(son[p][1], k);
		}
		else if(!son[p][0] && son[p][1])
		{
			spin(p, 1);
			del(son[p][0], k);
		}
		else
		{
			int t = (rnd[son[p][0]] < rnd[son[p][1]]);
			spin(p, t);
			del(son[p][t^1], k);
		}
		push_up(p);
		return;
	}
	int t = (val[p] < k);
	del(son[p][t], k);
	if(rnd[son[p][t]] > rnd[p])
		spin(p, t);
	push_up(p);
}
double query(int p, ll k, ll s1, int s2)
{
	if(!p)
		return inf;
	double t = (s1+sum[p]-sum[son[p][1]]+k)*1.0/(s2+siz[p]-siz[son[p][1]]);
	if(t > val[p])
		return min(query(son[p][1], k, s1+sum[p]-sum[son[p][1]], s2+siz[p]-siz[son[p][1]]), t);
	else
		return query(son[p][0], k, s1, s2);
}
int main()
{
	sed = time(0)%mod;
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		scanf("%d", &a[i]), ins(rt, a[i]);
	rep(i, 1, m)
	{
		int op, p;
		ll v;
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%d%lld", &p, &v);
			del(rt, a[p]);
			ins(rt, v);
			a[p] = v;
		}
		else
		{
			scanf("%lld", &v);
			printf("%.5lf\n", query(rt, v, 0, 0));
		}
	}
	return 0;
}