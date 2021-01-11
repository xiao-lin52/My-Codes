#include <bits/stdc++.h>
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
		register int f=1;
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
const int N = 2e5+10, inf = 0x3f3f3f3f;
int n, m, k, s[N], vis[N*10], bas[20], a[20];
void insert(int x)
{
	int t = x;
	for(int i = 20; i >= 0; i--)
		if((x>>i)&1)
			if(!bas[i])
			{
				bas[i] = x;
				a[++k] = t;
				break;
			}
			else
				x ^= bas[i];
}
void dfs(int x, int num)
{
	printf("%d ", num);
	if(x == (1<<m))
		exit(0);
	vis[num] = 1;
	for(int i = 1; i <= k; i++)
		if(!vis[num^a[i]])
			dfs(x+1, num^a[i]);
}
int main()
{
	read(n);
	for(int i = 1; i <= n; i++)
		read(s[i]);
	sort(s+1, s+1+n);
	for(int i = 0, j = 1; i <= 20 && j <= n; i++)
	{
		while(s[j] < (1<<i) && j <= n)
			insert(s[j++]);
		if(k == i)
			m = i;
	}
	printf("%d\n", m);
	k = 0;
	memset(bas, 0, sizeof(bas));
	for(int i = 1; i <= n; i++)
		if(s[i] < (1<<m))
			insert(s[i]);
	dfs(1, 0);
	return 0;
}