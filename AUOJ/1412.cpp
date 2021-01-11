#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define rep(i, l, r) for(register int i = (l); i <= (r); i++)
#define min(a, b) (a < b ? a : b)
using namespace std;
namespace IO
{
	char buf[1<<23],*p1=buf,*p2=buf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
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
}
using namespace IO;
const int N = 1e6+10, mod = 1e9+7;
int n, m, sed, u[N], v[N], in[N], ans[N];
vector<int> f[N];
int find(int x, int p)
{
	return f[x][p] == x ? f[x][p] : f[x][p] = find(f[x][p], p);
}
int main()
{
	sed = time(0)%mod;
	read(n);
	read(m);
	rep(i, 1, m)
	{
		read(u[i]);
		read(v[i]);
		in[u[i]]++;
		in[v[i]]++;
	}
	rep(i, 1, n)
	{
		f[i].push_back(0);
		rep(j, 1, in[i])
			f[i].push_back(i);
	}
	register int tot = 1;
	rep(i, 1, m)
	{
		register int l = 1, r = min(in[u[i]], in[v[i]]);
		while(l < r)
		{
			register int mid = (l+r)>>1;
			if(find(u[i], mid) == find(v[i], mid))
				l = mid+1;
			else
				r = mid;
		}
		f[find(u[i], l)][l] = find(v[i], l);
		printf("%d\n", l);
	}
	return 0;
}