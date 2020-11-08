#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10,mod=1e4+7;
ll n,sum,mx,fa[N],w[N],son[N][3];
vector<ll> edge[N];
void dfs(ll u,ll father)
{
	fa[u]=father;
	for(int i=0;i<edge[u].size();i++)
	{
		ll v=edge[u][i];
		if(v!=fa[u])
		{
			dfs(v,u);
			mx=max(mx,son[v][1]*w[u]);
			sum=(sum+w[v]*son[u][0]%mod+w[u]*son[v][0]%mod)%mod;
			son[u][0]+=w[v];
			if(son[u][1]<w[v])
			{
				son[u][2]=son[u][1];
				son[u][1]=w[v];
			}
			else
				if(son[u][2]<w[v])
					son[u][2]=w[v];
		}
	}
	mx=max(mx,son[u][1]*son[u][2]);
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n-1;i++)
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	dfs(1,0);
	printf("%lld %lld",mx,sum*2%mod);
	return 0;
}