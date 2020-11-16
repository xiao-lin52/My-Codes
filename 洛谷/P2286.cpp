#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=8e4+10,mod=1e6,inf=1e9;
ll n,tot,ans,rt[2],val[N][2],num[N][2],fa[N][2],son[N][2][2];
ll get(ll p,int q)
{
	return val[p][q]>val[fa[p][q]][q];
}
void clear(ll p,int q)
{
	fa[son[p][0][q]][q]=fa[son[p][1][q]][q]=fa[p][q];
	son[fa[p][q]][get(p,q)][q]=0;
	val[p][q]=num[p][q]=fa[p][q]=son[p][0][q]=son[p][1][q]=0;
}
void spin(ll p,int q)
{
	ll x=fa[p][q],y=fa[x][q],s=get(p,q);
	son[y][get(x,q)][q]=p;
	fa[x][q]=p;
	fa[p][q]=y;
	fa[son[p][s^1][q]][q]=x;
	son[x][s][q]=son[p][s^1][q];
	son[p][s^1][q]=x;
}
void splay(ll p,int q)
{
	for(int f;f=fa[p][q];spin(p,q))
		if(fa[f][q])
			spin((get(f,q)==get(p,q) ? f : p),q);
	rt[q]=p;
}
void find(ll k,int q)
{
	ll p=rt[q];
	while(1)
	{
		if(!p)
			return;
		if(val[p][q]==k)
		{
			splay(p,q);
			return;
		}
		else if(val[p][q]>k)
			p=son[p][0][q];
		else
			p=son[p][1][q];
	}
}
void ins(ll k,int q)
{
	if(!rt[q])
	{
		rt[q]=++tot;
		val[rt[q]][q]=k;
		num[rt[q]][q]=1;
		return;
	}
	ll p=rt[q],f=0;
	while(1)
	{
		if(!p)
		{
			p=++tot;
			val[p][q]=k;
			num[p][q]=1;
			fa[p][q]=f;
			son[f][get(p,q)][q]=p;
			splay(p,q);
			return;
		}
		if(val[p][q]==k)
		{
			num[p][q]++;
			splay(p,q);
			return;
		}
		ll t=(val[p][q]<k);
		f=p;
		p=son[p][t][q];
	}
}
ll getpre(ll k,int q)
{
	ll p=rt[q],res=-inf,j=0;
	while(1)
	{
		if(!p)
		{
			if(j)
				splay(j,q);
			return res;
		}
		if(val[p][q]>k)
			p=son[p][0][q];
		else
		{
			if(res<val[p][q])
			{
				res=val[p][q];
				j=p;
			}
			p=son[p][1][q];
		}
	}
}
ll getsuf(ll k,int q)
{
	ll p=rt[q],res=inf,j=0;
	while(1)
	{
		if(!p)
		{
			if(j)
				splay(j,q);
			return res;
		}
		if(val[p][q]<k)
			p=son[p][1][q];
		else
		{
			if(res>val[p][q])
			{
				res=val[p][q];
				j=p;
			}
			p=son[p][0][q];
		}
	}
}
void del(ll k,int q)
{
	find(k,q);
	if(num[rt[q]][q]>1)
	{
		num[rt[q]][q]--;
		return;
	}
	if(!son[rt[q]][0][q]&&!son[rt[q]][1][q])
	{
		rt[q]=0;
		clear(rt[q],q);
	}
	else if(!son[rt[q]][0][q])
	{
		ll t=son[rt[q]][1][q];
		clear(rt[q],q);
		rt[q]=t;
	}
	else if(!son[rt[q]][1][q])
	{
		ll t=son[rt[q]][0][q];
		clear(rt[q],q);
		rt[q]=t;
	}
	else
	{
		ll p=son[rt[q]][1][q];
		getpre(k,q);
		clear(son[rt[q]][1][q],q);
		son[rt[q]][1][q]=p;
	}
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		ll op,x;
		scanf("%lld%lld",&op,&x);
		if(op==0)
			if(rt[1])
			{
				ll t1=getpre(x,1),t2=getsuf(x,1);
				if(x-t1<=t2-x)
				{
					ans=(ans+x-t1)%mod;
					del(t1,1);
				}
				else
				{
					ans=(ans+t2-x)%mod;
					del(t2,1);
				}
			}
			else
				ins(x,0);
		else
			if(rt[0])
			{
				ll t1=getpre(x,0),t2=getsuf(x,0);
				if(x-t1<=t2-x)
				{
					ans=(ans+x-t1)%mod;
					del(t1,0);
				}
				else
				{
					ans=(ans+t2-x)%mod;
					del(t2,0);
				}
			}
			else
				ins(x,1);
	}
	printf("%lld",ans);
	return 0;
}