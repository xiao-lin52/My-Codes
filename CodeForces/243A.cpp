#include<bits/stdc++.h>
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
}
using namespace IO;
typedef long long ll;
const int N = 1e5+10;
struct QwQ
{
	int val;
	int id;
	bool operator < (const QwQ &a) const
	{
		return val == a.val ? id < a.id : val < a.val;
	}
};
QwQ t[30];
int n, mx, a[N], b[N*15], nxt[30];
ll ans;
int main()
{
	read(n);
	for(int i = 1; i <= n; i++)
		read(a[i]);
	for(int i = n; i >= 1; i--)
	{
		int x = a[i];
		for(int j = 0; j <= 20; j++)
		{
			t[j] = (QwQ){nxt[j], j};
			if((a[i]>>j)&1)
				nxt[j] = i;
		}
		sort(t, t+21);
		for(int j = 0; j <= 20; j++)
			if(t[j].val)
			{
				if(!b[x] && (j == 0 || t[j].val != t[j-1].val))
				{
					ans++;
					b[x] = 1;
				}
				x |= (1<<t[j].id);
			}
		if(!b[x])
		{
			ans++;
			b[x] = 1;
		}
	}
	printf("%lld", ans);
	return 0;
}
