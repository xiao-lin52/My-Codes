#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,inf=1e9;
int n,m,dt,ans,rt,tot,val[N],num[N],siz[N],fa[N],son[N][2];
int get(int p)
{
	return val[p]>val[fa[p]];
}
inline void push_up(int p)
{
	siz[p]=siz[son[p][0]]+siz[son[p][1]]+num[p];
}
inline void spin(int &p)
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
			spin(get(p)==get(f) ? f : p);
	rt=p;
}
inline void ins(int k)
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
			num[p]=siz[p]=1;
			fa[p]=f;
			son[f][get(p)]=p;
			break;
		}
		if(val[p]==k)
		{
			num[p]++;
			siz[p]++;
			break;
		}
		int t=(val[p]<k);
		f=p;
		p=son[p][t];
	}
	splay(p);
}
inline int getpre(int k)
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
	if(j)
		splay(j);
	return res;
}
inline int getkth(int k)
{
	int p=rt;
	while(1)
	{
		if(!p)
			return -inf;
		if(siz[son[p][1]]>=k)
			p=son[p][1];
		else if(siz[son[p][1]]+num[p]>=k)
		{
			splay(p);
			return val[rt];
		}
		else
		{
			k-=siz[son[p][1]]+num[p];
			p=son[p][0];
		}
	}
}
inline void del(int k)
{
	int t=getpre(k+1);
	if(t!=-inf)
	{
		ans+=siz[son[rt][0]]+num[rt];
		fa[son[rt][1]]=0;
		rt=son[rt][1];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char op[10];
		int x;
		scanf("%s%d",op,&x);
		if(op[0]=='I')
		{
			if(x>=m)
				ins(x+dt);
		}
		else if(op[0]=='A')
			dt-=x;
		else if(op[0]=='S')
		{
			dt+=x;
			del(getpre(m+dt));
		}
		else
		{
			int t=getkth(x);
			if(t==-inf)
				printf("-1\n");
			else
				printf("%d\n",t-dt);
		}
	}
	printf("%d",ans);
	return 0;
}