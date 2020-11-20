#include<bits/stdc++.h>
#define rd() sed=sed*1919810ll%mod
#define push_up(p) siz[p]=siz[son[p][0]]+siz[son[p][1]]+num[p]
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<24,stdin),p1==p2)?EOF:*p1++)
using namespace std;
const int N=1e5+10,mod=1e9+7,inf=1e9;
int n,m,dt,ans,rt,tot,sed,flag,val[N],num[N],rnd[N],siz[N],son[N][2];
char buf[1<<25],*p1=buf,*p2=buf,obuf[1<<25],*O=obuf;
template<typename T> inline void read(T &x)
{
	x=0;
	register char ch=getchar();
	while(!isdigit(ch))
	{
		if(isalpha(ch))
		{
			x=ch;
			return;
		}
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
}
void spin(int &p,int s)
{
	int t=son[p][s];
	son[p][s]=son[son[p][s]][s^1];
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
		num[p]=siz[p]=1;
		rnd[p]=rd();
		return;
	}
	if(val[p]==k)
	{
		num[p]++;
		siz[p]++;
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
	if(val[p]>k)
		del(son[p][0],k);
	else if(val[p]<k)
	{
		del(son[p][1],k);
		ans+=siz[son[p][0]]+num[p];
		p=son[p][1];
	}
	else if(val[p]==k)
	{
		ans+=siz[son[p][0]]+num[p];
		p=son[p][1];
	}
	push_up(p);
}
int getpre(int p,int k)
{
	if(!p)
		return -inf;
	if(val[p]>=k)
		return getpre(son[p][0],k);
	else
		return max(val[p],getpre(son[p][1],k));
}
int getkth(int p,int k)
{
	if(!p)
		return -1;
	if(siz[son[p][1]]>=k)
		return getkth(son[p][1],k);
	else if(siz[son[p][1]]+num[p]>=k)
		return val[p];
	else
		return getkth(son[p][0],k-siz[son[p][1]]-num[p]);
}
int main()
{
	sed=time(0);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		char op;
		int x;
		read(op);
		read(x);
		if(op=='I')
		{
			if(x>=m)
				ins(rt,x+dt);
		}
		else if(op=='A')
			dt-=x;
		else if(op=='S')
		{
			dt+=x;
			del(rt,getpre(rt,m+dt));
		}
		else
		{
			int t=getkth(rt,x);
			if(t==-1)
				printf("-1\n");
			else
				printf("%d\n",t-dt);
		}
	}
	printf("%d",ans);
	return 0;
}