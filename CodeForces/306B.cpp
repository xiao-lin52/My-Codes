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
const int N = 2e5 + 10;
struct Operation
{
	int x;
	int y;
	int id;
	bool operator < (Operation const &a) const
	{
		return x == a.x ? y > a.y : x < a.x;
	}
};
Operation q[N];
int n, m, flag, k, p[N];
int main()
{
	read(n, m);
	for(int  i = 1; i <= m; i++)
	{
		int x, l;
		read(x, l);
		q[i] = (Operation){x, x+l-1, i};
	}
	sort(q+1, q+1+m);
	for(int i = 1; i <= m; i++)
		if(q[i].x > flag)
		{
			register int j, mx = q[i].y, mxj = i;
			for(j = i+1; j <= m; j++)
			{
				if(q[j].x > q[i].y+1)
					break;
				if(q[j].y > mx)
				{
					mx = q[j].y;
					mxj = j;
				}
			}
			p[q[i].id] = 1;
			k++;
			if(mx == q[i].y)
				flag = q[i].y;
			else
				flag = q[mxj].x-1;
		}
	printf("%d\n", m-k);
	for(int i = 1; i <= m; i++)
		if(!p[i])
			printf("%d ", i);
	return 0;
}