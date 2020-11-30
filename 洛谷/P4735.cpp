#include<bits/stdc++.h>
const int N=6e5+10;
using namespace std;
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
int n,m,tot,cnt,sum,val[N*35],son[N*35][2],rt[N];
void insert(int i,int j,int x)
{
	for(int k=25;k>=0;k--)
	{
		son[j][0]=son[i][0];
		son[j][1]=son[i][1];
		int s=((x>>k)&1);
		son[j][s]=++tot;
		i=son[i][s];
		j=son[j][s];
		val[j]=val[i]+1;
	}
}
int query(int i,int j,int x)
{
	int ans=0;
	for(int k=25;k>=0;k--)
	{
		int s=(((x>>k)&1)^1);
		if(val[son[j][s]]-val[son[i][s]])
		{
			i=son[i][s];
			j=son[j][s];
			ans|=(s<<k);
		}
		else
		{
			i=son[i][s^1];
			j=son[j][s^1];
			ans|=((s^1)<<k);
		}
	}
	return x^ans;
}
int main()
{
	read(n,m);
	rt[0]=++tot;
	insert(rt[0],rt[0],0);
	for(int i=1;i<=n;i++)
	{
		int a;
		rt[++cnt]=++tot;
		read(a);
		sum^=a;
		insert(rt[cnt-1],rt[cnt],sum);
	}
	for(int i=1;i<=m;i++)
	{
		char op;
		int l,r,x;
		readc(op);
		if(op=='A')
		{
			read(x);
			rt[++cnt]=++tot;
			sum^=x;
			insert(rt[cnt-1],rt[cnt],sum);
		}
		else
		{
			read(l,r,x);
			x^=sum;
			if(l==1)
				printf("%d\n",query(0,rt[r-1],x));
			else
				printf("%d\n",query(rt[max(l-2,0)],rt[r-1],x));
		}
	}
	return 0;
}