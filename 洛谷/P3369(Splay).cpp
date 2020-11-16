#include<bits/stdc++.h>
#define get(p) (val[p]>val[fa[p]])
using namespace std;
const int N=1e5+10,inf=1e9;
int n,tot,rt,val[N],num[N],siz[N],fa[N],son[N][2];
inline void push_up(int p)
{
	siz[p]=siz[son[p][0]]+siz[son[p][1]]+num[p];
}
inline void clear(int p)
{
	fa[son[p][0]]=fa[son[p][1]]=fa[p];
	son[fa[p]][get(p)]=0;
	val[p]=num[p]=siz[p]=fa[p]=son[p][0]=son[p][1]=0;
}
inline void spin(int p)
{
	int x=fa[p],y=fa[x],s=get(p);
	son[y][get(x)]=p;
	fa[x]=p;
	fa[p]=y;
	fa[son[p][s^1]]=x;
	son[x][s]=son[p][s^1];
	son[p][s^1]=x;
	push_up(x);
	push_up(p);
}
inline void splay(int p)
{
	for(int f;f=fa[p];spin(p))
		if(fa[f])
			spin(get(f)==get(p) ? f : p);
	rt=p;
}
void ins(int k)
{
	if(!rt)
	{
		rt=++tot;
		val[rt]=k;
		num[rt]=siz[rt]=1;
		return;
	}
	int p=rt,f=0;
	while(1)
	{
		if(!p)
		{
			p=++tot;
			val[p]=k;
			fa[p]=f;
			son[f][get(p)]=p;
			num[p]=siz[p]=1;
			splay(p);
			return;
		}
		if(val[p]==k)
		{
			num[p]++;
			siz[p]++;
			splay(p);
			return;
		}
		int t=(val[p]<k);
		f=p;
		p=son[p][t];
	}
}
int getrnk(int k)
{
	int p=rt,res=0;
	while(1)
	{
		if(!p)
			return 0;
		if(val[p]==k)
		{
			res+=siz[son[p][0]]+1;
			splay(p);
			return res;
		}
		else if(val[p]>k)
			p=son[p][0];
		else
		{
			res+=num[p]+siz[son[p][0]];
			p=son[p][1];
		}
	}
}
int getkth(int k)
{
	int p=rt,res=0;
	while(1)
	{
		if(!p)
			return 0;
		if(siz[son[p][0]]>=k)
			p=son[p][0];
		else if(siz[son[p][0]]+num[p]<k)
		{
			k-=siz[son[p][0]]+num[p];
			p=son[p][1];
		}
		else
		{
			splay(p);
			return val[rt];
		}
	}
}
int getpre(int k)
{
	int p=rt,res=-inf,j=0;
	while(1)
	{
		if(!p)
			break;
		if(val[p]>=k)
			p=son[p][0];
		else
		{
			if(res<val[p])
			{
				res=val[p];
				j=p;
			}
			p=son[p][1];
		}
	}
	splay(j);
	return res;
}
int getsuf(int k)
{
	int p=rt,res=inf,j=0;
	while(1)
	{
		if(!p)
			break;
		if(val[p]<=k)
			p=son[p][1];
		else
		{
			if(res>val[p])
			{
				res=val[p];
				j=p;
			}
			p=son[p][0];
		}
	}
	splay(j);
	return res;
}
void del(int k)
{
	getrnk(k);
	if(num[rt]>1)
	{
		num[rt]--;
		siz[rt]--;
		return;
	}
	if(!son[rt][0]&&!son[rt][1])
	{
		rt=0;
		clear(rt);
		return;
	}
	else if(!son[rt][0]&&son[rt][1])
	{
		int x=son[rt][1];
		clear(rt);
		rt=x;
	}
	else if(son[rt][0]&&!son[rt][1])
	{
		int x=son[rt][0];
		clear(rt);
		rt=x;
	}
	else
	{
		int t=son[rt][1];
		getpre(k);
		int x=son[t][1];
		clear(son[rt][1]);
		son[rt][1]=t;
	}
	push_up(rt);
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(op==1)
			ins(x);
		else if(op==2)
			del(x);
		else if(op==3)
			printf("%d\n",getrnk(x));
		else if(op==4)
			printf("%d\n",getkth(x));
		else if(op==5)
			printf("%d\n",getpre(x));
		else
			printf("%d\n",getsuf(x));
	}
	return 0;
}