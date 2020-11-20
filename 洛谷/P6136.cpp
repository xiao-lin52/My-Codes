#include<bits/stdc++.h>
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
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
const int N=2e6+10,mod=1e7+9,inf=(1ll<<31)-1;
int n,m,tot,sed,rt,ans,lastans,flag,son[N][2],val[N],num[N],rnd[N],siz[N];
int rd()
{
	return sed=1ll*sed*20060209ll%mod;
}
inline void push_up(int p)
{
	siz[p]=siz[son[p][0]]+siz[son[p][1]]+num[p];
}
inline void spin(int &p,int s)
{
	int t=son[p][s];
	son[p][s]=son[t][s^1];
	son[t][s^1]=p;
	push_up(p);
	push_up(t);
	p=t;
}
void ins(int &p,int k)
{
	if(!p)
	{
		p=++tot;
		val[p]=k;
		rnd[p]=rd();
		son[p][0]=son[p][1]=0;
		num[p]=siz[p]=1;
		return;
	}
	if(val[p]==k)
	{
		siz[p]++;
		num[p]++;
		return;
	}
	int t=(val[p]<k);
	ins(son[p][t],k);
	if(rnd[son[p][t]]>rnd[p])
		spin(p,t);
	push_up(p);
}
void del(int &p,int k)
{
	if(!p)
		return;
	if(val[p]==k)
	{
		if(!son[p][0]&&!son[p][1])
		{
			num[p]--;
			siz[p]--;
			if(!num[p])
				p=0;
		}
		else if(son[p][0]&&!son[p][1])
		{
			spin(p,0);
			del(son[p][1],k);
		}
		else if(!son[p][0]&&son[p][1])
		{
			spin(p,1);
			del(son[p][0],k);
		}
		else if(son[p][0]&&son[p][1])
		{
			int t=(rnd[son[p][0]]<rnd[son[p][1]]);
			spin(p,t);
			del(son[p][t^1],k);
		}
		push_up(p);
		return;
	}
	int t=(val[p]<k);
	del(son[p][t],k);
	if(rnd[son[p][t]]>rnd[p])
		spin(p,t);
	push_up(p);
}
int getrnk(int p,int k)
{
	if(!p)
		return 1;
	if(val[p]==k)
		return siz[son[p][0]]+1;
	else if(val[p]>k)
		return getrnk(son[p][0],k);
	else
		return getrnk(son[p][1],k)+siz[son[p][0]]+num[p];
}
int getkth(int p,int k)
{
	if(!p)
		return 0;
	if(siz[son[p][0]]>=k)
		return getkth(son[p][0],k);
	else if(siz[son[p][0]]+num[p]<k)
		return getkth(son[p][1],k-siz[son[p][0]]-num[p]);
	else
		return val[p];
}
int getpre(int p,int k)
{
	if(!p)
		return -inf;
	if(val[p]>=k)
		return getpre(son[p][0],k);
	else
		return max(getpre(son[p][1],k),val[p]);
}
int getsuf(int p,int k)
{
	if(!p)
		return inf;
	if(val[p]<=k)
		return getsuf(son[p][1],k);
	else
		return min(getsuf(son[p][0],k),val[p]);
}
int main()
{
	sed=time(0);
	read(n,m);
	for(int i=1;i<=n;i++)
	{
		int a;
		read(a);
		ins(rt,a);
	}
	while(m--)
	{
		int op,x,t=0;
		read(op,x);
		x^=lastans;
		if(op==1)
			ins(rt,x);
		else if(op==2)
			del(rt,x);
		else if(op==3)
			t=getrnk(rt,x);
		else if(op==4)
			t=getkth(rt,x);
		else if(op==5)
			t=getpre(rt,x);
		else
			t=getsuf(rt,x);
		ans^=t;
		if(op==3||op==4||op==5||op==6)
			lastans=t;
	}
	printf("%d",ans);
	return 0;
}