#include<bits/stdc++.h>
namespace IO
{
	template <typename T> inline void read(T &x)
	{
		x=0;
		register char c=getchar();
		while(c<'0'||c>'9')
			c=getchar();
		while(c>='0'&&c<='9')
			x=x*10+c-'0',c=getchar();
	}
}
using namespace IO;
using namespace std;
typedef long long ll;
const ll N=1e5+10,mod=1e9+7;
struct QwQ
{
	ll val;
	ll id;
	inline bool operator < (QwQ a)
	{
		return val>a.val;
	}
};
struct Edge
{
	int nxt;
	int to;
};
Edge edge[N<<1];
QwQ in[N];
ll n,m,ans,k,a[N],sum[N],cnt[N],vis[N],p[N],flag[N],head[N];
inline void add_edge(ll u,ll v)
{
	k++;
	edge[k].nxt=head[u];
	edge[k].to=v;
	head[u]=k;
}
int main()
{
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		in[i].id=i;
	}
	for(int i=1;i<=m;i++)
	{
		ll u,v;
		read(u);
		read(v);
		add_edge(u,v);
		add_edge(v,u);
		in[u].val++;
		in[v].val++;
	}
	sort(in+1,in+1+n);
	for(register int i=1;i<=n;i++)
	{
		register int v1=in[i].id;
		for(register int j=head[v1];j;j=edge[j].nxt)
		{
			register int v2=edge[j].to;
			if(!p[v2]&&v2!=v1)
				for(register int k=head[v2];k;k=edge[k].nxt)
				{
					register int v3=edge[k].to;
					if(!p[v3]&&v3!=v2&&v3!=v1)
					{
						if(flag[v3]!=i)
						{
							cnt[v3]=1;
							sum[v3]=(a[v1]+a[v2]+a[v3])%mod;
							flag[v3]=i;
						}
						else
						{
							ans=(ans+cnt[v3]*a[v2]%mod+sum[v3])%mod;
							cnt[v3]=(cnt[v3]+1)%mod;
							sum[v3]=(sum[v3]+(a[v1]+a[v2]+a[v3])%mod)%mod;
						}
					}
				}
		}
		p[v1]=1;
	}
	printf("%lld",ans);
	return 0;
}