#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=8e4+10,mod=1e6,inf=2147483648;
struct Splay
{
	ll rt,tot,val[N],son[N][2],fa[N];
	ll empty()
	{
		return rt;
	}
	ll get(ll p)
	{
		return val[p]>val[fa[p]];
	}
	void clear(ll p)
	{
		son[fa[p]][get(p)]=son[p][0] ? son[p][0] : son[p][1];
		fa[son[p][0]]=fa[son[p][1]]=fa[p];
		fa[p]=val[p]=0;
	}
	void spin(ll p)
	{
		ll x=fa[p],y=fa[x],s=get(p);
		son[y][get(x)]=p;
		fa[x]=p;
		fa[p]=y;
		fa[son[p][s^1]]=x;
		son[x][s]=son[p][s^1];
		son[p][s^1]=x;
	}
	void splay(ll p)
	{
		for(ll f;f=fa[p];spin(p))
			if(fa[f])
				spin(get(p)==get(f) ? f : p);
		rt=p;
	}
	void find(ll k)
	{
		ll p=rt;
		while(1)
		{
			if(!p)
				return;
			if(val[p]==k)
				break;
			ll t=(val[p]<k);
			p=son[p][t];
		}
		splay(p);
	}
	void ins(ll k)
	{
		if(!rt)
		{
			rt=++tot;
			val[rt]=k;
			return;
		}
		ll p=rt,f=0;
		while(1)
		{
			if(!p)
			{
				p=++tot;
				val[p]=k;
				fa[p]=f;
				son[fa[p]][get(p)]=p;
				break;
			}
			ll t=(val[p]<k);
			f=p;
			p=son[p][t];
		}
		splay(p);
	}
	ll getpre(ll k)
	{
		ll p=rt,res=-inf,x=0;
		while(1)
		{
			if(!p)
				break;
			if(val[p]>k)
				p=son[p][0];
			else
			{
				if(val[p]>res)
				{
					res=val[p];
					x=p;
				}
				p=son[p][1];
			}
		}
		if(x)
			splay(x);
		return res;
	}
	ll getsuf(ll k)
	{
		ll p=rt,res=inf,x=0;
		while(1)
		{
			if(!p)
				break;
			if(val[p]<k)
				p=son[p][1];
			else
			{
				if(val[p]<res)
				{
					res=val[p];
					x=p;
				}
				p=son[p][0];
			}
		}
		if(x)
			splay(x);
		return res;
	}
	void del(ll k)
	{
		getpre(k);
		if(!son[rt][0]&&!son[rt][1])
			rt=0;
		else if(!son[rt][0])
		{
			ll x=son[rt][1];
			clear(rt);
			rt=x;
		}
		else if(!son[rt][1])
		{
			ll x=son[rt][0];
			clear(rt);
			rt=x;
		}
		else
		{
			ll x=rt;
			getpre(val[rt]-1);
			clear(x);
		}
	}
};
Splay pet,people;
ll n,ans;
signed main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		ll a,b;
		scanf("%lld%lld",&a,&b);
		if(a==0)
			if(people.empty())
			{
				ll x=people.getpre(b),y=people.getsuf(b);
				if(b-x<=y-b)
				{
					ans=(ans+b-x)%mod;
					people.del(x);
				}
				else
				{
					ans=(ans+y-b)%mod;
					people.del(y);
				}
			}
			else
				pet.ins(b);
		else
			if(pet.empty())
			{
				ll x=pet.getpre(b),y=pet.getsuf(b);
				if(b-x<=y-b)
				{
					ans=(ans+b-x)%mod;
					pet.del(x);
				}
				else
				{
					ans=(ans+y-b)%mod;
					pet.del(y);
				}
			}
			else
				people.ins(b);
	}
	printf("%lld",ans);
	return 0;
}