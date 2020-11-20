#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	char buf[1<<23],*p1=buf,*p2=buf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
}
using namespace IO;
const int N=1e5+10;
int n,m,q,val[N],fa[N],siz[N],son[N][2],f[N];
int find(int x)
{
	return f[x]==x ? f[x] : f[x]=find(f[x]);
}
int get(int p)
{
	return val[fa[p]]<val[p];
}
void push_up(int p)
{
	siz[p]=siz[son[p][0]]+siz[son[p][1]]+1;
}
void spin(int p)
{
	int x=fa[p],y=fa[x],s=get(p),t=get(x);
	fa[x]=p;
	fa[p]=y;
	fa[son[p][s^1]]=x;
	son[y][t]=p;
	son[x][s]=son[p][s^1];
	son[p][s^1]=x;
	push_up(x);
	push_up(p);
}
void splay(int p)
{
	for(int f;f=fa[p];spin(p))
		if(fa[f])
			spin(get(p)==get(f) ? f : p);
	f[find(p)]=p;
	f[p]=p;
}
void ins(int x,int rt)
{
	int p=rt,t=0;
	while(1)
	{
		if(!p)
		{
			f[x]=fa[x]=fa[x]=t;
			son[t][get(x)]=x;
			son[x][0]=son[x][1]=0;
			siz[x]=1;
			splay(x);
			return;
		}
		int s=(val[p]<val[x]);
		t=p;
		p=son[p][s];
	}
}
int getkth(int k,int rt)
{
	int p=rt;
	if(siz[p]<k)
		return -1;
	while(1)
	{
		if(!p)
			return -1;
		if(siz[son[p][0]]>=k)
			p=son[p][0];
		else if(siz[son[p][0]]+1>=k)
		{
			splay(p);
			return p;
		}
		else
		{
			k-=siz[son[p][0]]+1;
			p=son[p][1];
		}
	}
}
void merge(int x,int y)
{
	if(!x)
		return;
	merge(son[x][0],y);
	merge(son[x][1],y);
	ins(x,y);
}
int main()
{
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		read(val[i]);
		f[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		read(u);
		read(v);
		int t1=find(u),t2=find(v);
		if(t1==t2)
			continue;
		if(siz[t1]<siz[t2])
			merge(t1,t2);
		else
			merge(t2,t1);
	}
	read(q);
	for(int i=1;i<=q;i++)
	{
		char op;
		int x,y;
		read(op);
		read(x);
		read(y);
		if(op=='Q')
			printf("%d\n",getkth(y,find(x)));
		else
		{
			int t1=find(x),t2=find(y);
			if(t1==t2)
				continue;
			if(siz[t1]<siz[t2])
				merge(t1,t2);
			else
				merge(t2,t1);
		}
	}
	return 0;
}