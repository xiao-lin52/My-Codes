#include <bits/stdc++.h>
#define judge(x) (tree[x].lz == tree[x].r-tree[x].l+1)
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
typedef long long ll;
const int N = 8e4+10, inf = 0x3f3f3f3f, mod = 777777777;
struct SegTree
{
	int l;
	int r;
	int lz;
	int rz;
	int ln;
	int rn;
	ll dat;
};
SegTree tree[N<<2];
int n, m, a[10][10];
ll f[N][10][10];
inline void push_up(int i)
{
	tree[i].lz = tree[i<<1].lz;
	tree[i].rz = tree[i<<1|1].rz;
	tree[i].ln = tree[i<<1].ln;
	tree[i].rn = tree[i<<1|1].rn;
	if(judge(i<<1) && judge(i<<1|1))
	{
		tree[i].lz = tree[i].rz = tree[i].r-tree[i].l+1;
		tree[i].dat = 1;
	}
	if(judge(i<<1) && !judge(i<<1|1))
	{
		tree[i].lz += tree[i<<1|1].lz;
		tree[i].ln = tree[i<<1|1].ln;
		tree[i].dat = tree[i<<1|1].dat;
	}
	if(!judge(i<<1) && judge(i<<1|1))
	{
		tree[i].rz += tree[i<<1].rz;
		tree[i].rn = tree[i<<1].rn;
		tree[i].dat = tree[i<<1].dat;
	}
	if(!judge(i<<1) && !judge(i<<1|1))
	{
		tree[i].dat = tree[i<<1].dat*tree[i<<1|1].dat%mod;
		if(tree[i<<1].rz || tree[i<<1|1].lz)
		{
			ll t = 0;
			for(int j = 1; j <= 3; j++)
				for(int k = 1; k <= 3; k++)
					if(a[tree[i<<1].rn][j] && a[k][tree[i<<1|1].ln])
						t = (t+f[tree[i<<1].rz+tree[i<<1|1].lz][j][k])%mod;
			tree[i].dat = tree[i].dat*t%mod;
		}
	}
	if(!tree[i<<1].rz && !tree[i<<1|1].lz && !a[tree[i<<1].rn][tree[i<<1|1].ln])
		tree[i].dat = 0;
}
void build(int i, int l, int r)
{
	tree[i].l = l;
	tree[i].r = r;
	tree[i].lz = tree[i].rz = r-l+1;
	tree[i].dat = 1;
	if(l == r)
		return;
	int mid = (l+r)>>1;
	build(i<<1, l, mid);
	build(i<<1|1, mid+1, r);
}
void update(int i, int x, int k)
{
	if(tree[i].l == tree[i].r)
	{
		if(k)
			tree[i].lz = tree[i].rz = 0;
		else
			tree[i].lz = tree[i].rz = 1;
		tree[i].ln = tree[i].rn = k;
		return;
	}
	if(tree[i<<1].r >= x)
		update(i<<1, x, k);
	else
		update(i<<1|1, x, k);
	push_up(i);
}
ll query()
{
	if(tree[1].lz == n)
	{
		ll t = 0;
		for(int i = 1; i <= 3; i++)
			for(int j = 1; j <= 3; j++)
				t = (t+f[n][i][j])%mod;
		return t;
	}
	ll ans = tree[1].dat;
	if(tree[1].lz)
	{
		ll t = 0;
		for(int i = 1; i <= 3; i++)
			for(int j = 1; j <= 3; j++)
				if(a[j][tree[1].ln])
					t = (t+f[tree[1].lz][i][j])%mod;
		ans = ans*t%mod;
	}
	if(tree[1].rz)
	{
		ll t = 0;
		for(int i = 1; i <= 3; i++)
			for(int j = 1; j <= 3; j++)
				if(a[tree[1].rn][i])
					t = (t+f[tree[1].rz][i][j])%mod;
		ans = ans*t%mod;
	}
	return ans;
}
signed main()
{
	read(n, m);
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			read(a[i][j]);
	f[1][1][1] = f[1][2][2] = f[1][3][3] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= 3; j++)
			for(int k = 1; k <= 3; k++)
				for(int l = 1; l <= 3; l++)
					if(a[l][k])
						f[i][j][k] = (f[i][j][k]+f[i-1][j][l])%mod;
	build(1, 1, n);
	for(int i = 1; i <= m; i++)
	{
		int v;
		ll t;
		read(v, t);
		update(1, v, t);
		printf("%lld\n", query());
	}
	return 0;
}