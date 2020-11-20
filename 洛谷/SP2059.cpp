#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Number
{
	int v;
	int c;
	int id;
};
bool cmp1(Number a,Number b)
{
	return (a.v==b.v) ? (a.id<b.id) : (a.v<b.v);
}
bool cmp2(Number a,Number b)
{
	return a.id<b.id;
}
Number a[N];
int n,rt,tot,val[N],siz[N],fa[N],mn[N],tag[N],son[N][2];
int get(int p)
{
	return p==son[fa[p]][1];
}
void push_up(int p)
{
	siz[p]=siz[son[p][0]]+siz[son[p][1]]+1;
	mn[p]=min(val[p],min(mn[son[p][0]],mn[son[p][1]]));
}
void push_down(int p)
{
	if(!tag[p])
		return;
	swap(son[p][0],son[p][1]);
	tag[son[p][0]]^=1;
	tag[son[p][1]]^=1;
	tag[p]^=1;
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
			spin(get(p)==get(f) ? f : p);
	if(!tar)
		rt=p;
}
void ins(int k,int id)
{
	if(!rt)
	{
		rt=++tot;
		val[rt]=k;
		siz[rt]=1;
		return;
	}
	int p=rt,f=0,t;
	while(p)
	{
		t=(siz[son[p][0]]<id);
		f=p;
		p=son[p][t];
	}
	p=++tot;
	val[p]=mn[p]=k;
	siz[p]=1;
	son[f][t]=p;
	fa[p]=f;
	splay(p,0);
}
int getrnk()
{
	int p=son[rt][1],res=siz[son[rt][0]]+1;
	while(1)
	{
		push_down(p);
		if(val[p]==mn[p])
			break;
		else if(mn[son[p][0]]<mn[son[p][1]])
			p=son[p][0];
		else
		{
			res+=siz[son[p][0]]+1;
			p=son[p][1];
		}
	}
	return res+siz[son[p][0]]+2;
}
void getkth(int k,int tar)
{
	int p=rt;
	while(1)
	{
		push_down(p);
		if(siz[son[p][0]]+1==k)
			break;
		else if(siz[son[p][0]]+1>k)
			p=son[p][0];
		else
		{
			k-=siz[son[p][0]]+1;
			p=son[p][1];
		}
	}
	splay(p,tar);
}
int rev(int k)
{
	getkth(k,0);
	getkth(getrnk(),rt);
	int res=siz[son[rt][0]]+siz[son[son[rt][1]][0]];
	tag[son[son[rt][1]][0]]^=1;
	return res;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		tot=rt=0;
		memset(fa,0,sizeof(fa));
		memset(mn,0,sizeof(mn));
		memset(son,0,sizeof(son));
		memset(val,0,sizeof(val));
		memset(siz,0,sizeof(siz));
		memset(tag,0,sizeof(tag));
		memset(mn,0x3f,sizeof(mn));
		ins(0,1);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i].v);
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++)
			a[i].c=a[i-1].c+1;
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++)
			ins(a[i].c,i+1);
		ins(10000001,n+2);
		for(int i=1;i<=n;i++)
		{
			printf("%d",rev(i));
			printf("%c",i==n ? '\n' : ' ');
		}
	}
	return 0;
}