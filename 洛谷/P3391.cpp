#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,rt,tot,val[N],siz[N],tag[N],fa[N],son[N][2];
int get(int p)
{
	return p==son[fa[p]][1];
}
void push_up(int p)
{
	siz[p]=siz[son[p][0]]+siz[son[p][1]]+1;
}
void push_down(int p)
{
	if(!tag[p])
		return;
	tag[son[p][0]]^=1;
	tag[son[p][1]]^=1;
	tag[p]=0;
	swap(son[p][0],son[p][1]);
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
void splay(int p,int tar)
{
	for(int f;tar!=(f=fa[p]);spin(p))
		if(tar!=fa[f])
			spin(get(f)==get(p) ? f : p);
	if(!tar)
		rt=p;
}
void ins(int k)
{
	if(!rt)
	{
		rt=++tot;
		val[rt]=k;
		siz[rt]=1;
		return;
	}
	int p=rt,f=0,t=0;
	while(1)
	{
		push_down(p);
		if(!p)
		{
			p=++tot;
			val[p]=k;
			fa[p]=f;
			son[f][t]=p;
			siz[rt]=1;
			break;
		}
		t=(siz[son[p][0]]<k);
		f=p;
		p=son[p][t];
	}
	splay(p,0);
}
int getkth(int k,int tar)
{
	int p=rt;
	while(1)
	{
		if(!p)
			return -1;
		push_down(p);
		if(siz[son[p][0]]>=k)
			p=son[p][0];
		else if(siz[son[p][0]]+1<k)
		{
			k-=siz[son[p][0]]+1;
			p=son[p][1];
		}
		else
		{
			splay(p,tar);
			return val[p];
		}
	}
}
void rev(int l,int r)
{
	getkth(l,0);
	getkth(r+2,rt);
	tag[son[son[rt][1]][0]]^=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++)
		ins(i);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		rev(l,r);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",getkth(i+1,0));
	return 0;
}