#include<bits/stdc++.h>
#define N 200010
#define Col 1000010
namespace IO
{
	char buf[1<<23],*p1=buf,*p2=buf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	#define isdigit(c) (c>=48&&c<=57)
	#define isalpha(c) (c>=65&&c<=90)
	template<typename T> inline void read(T &x)
	{
		x=0;
		register int f=1;
		register char ch=getchar();
		while(!isdigit(ch))
		{
			if(ch==45)
				f=-1;
			ch=getchar();
		}
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
		x*=f;
	}
	inline void reads(char x[])
	{
		register int cnt=0;
		register char ch=getchar();
		while(!isalpha(ch))
			ch=getchar();
		while(isalpha(ch))
		{
			x[cnt]=ch;
			cnt++;
			ch=getchar();
		}
	}
	inline void readc(char &x)
	{
		register char ch=getchar();
		while(!isalpha(ch))
			ch=getchar();
		x=ch;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
using namespace std;
int n,m,k,k1,len,lastc,num,cnt[Col],a[N],ans[N],belong[N];
struct Query
{
	int x;
	int y;
	int b;
	int id;
	bool operator < (Query const &a) const
	{
		return (belong[x]^belong[a.x]) ? belong[x]<belong[a.x] : (belong[y]^belong[a.y]) ? belong[y]<belong[a.y] : b<a.b;
	}
};
struct Change
{
	int p;
	int col;
};
Query q[N];
Change c[N];
int main()
{
	read(n,m);
	len=2000;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		belong[i]=(i-1)/len+1;
	}
	for(int i=1;i<=m;i++)
	{
		char op;
		int a,b;
		readc(op);
		read(a,b);
		if(op=='Q')
			q[++k]=Query{a,b,lastc,k};
		else
		{
			c[++k1]=Change{a,b};
			lastc=k1;
		}
	}
	sort(q+1,q+1+k);
	register int l=1,r=0,t=0;
	for(int i=1;i<=k;i++)
	{
		while(l<q[i].x)
			num-=!--cnt[a[l++]];
		while(l>q[i].x)
			num+=!cnt[a[--l]]++;
		while(r<q[i].y)
			num+=!cnt[a[++r]]++;
		while(r>q[i].y)
			num-=!--cnt[a[r--]];
		while(t<q[i].b)
		{
			t++;
			if(l<=c[t].p&&r>=c[t].p)
				num-=!--cnt[a[c[t].p]],num+=!cnt[c[t].col]++;
			swap(c[t].col,a[c[t].p]);
		}
		while(t>q[i].b)
		{
			if(l<=c[t].p&&r>=c[t].p)
				num-=!--cnt[a[c[t].p]],num+=!cnt[c[t].col]++;
			swap(c[t].col,a[c[t].p]);
			t--;
		}
		ans[q[i].id]=num;
	}
	for(int i=1;i<=k;i++)
		printf("%d\n",ans[i]);
	return 0;
}