#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10,mod=998244353;
ll n,m,q,mul[N],vis[N],a[N],in[N],f[N],fun[N][2];
vector<int> edge[N];
ll dfs(int u)
{
	if(vis[u])
		return mul[u];
	vis[u]=1;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		mul[u]=mul[u]*dfs(v)%mod;
	}
	return mul[u];
}
void topo()
{
	queue<int> q;
	for(int i=0;i<=m;i++)
		if(!in[i])
			q.push(i);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		ll rec=1;
		for(int i=edge[u].size()-1;i>=0;i--)
		{
			int v=edge[u][i];
			f[v]=(f[v]+f[u]*rec%mod)%mod;
			rec=rec*mul[v]%mod;
			in[v]--;
			if(!in[v])
				q.push(v);
		}
	}
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		mul[i]=1;
		ll op,p,v,c;
		int g;
		scanf("%lld",&op);
		if(op==1)
			scanf("%lld%lld",&fun[i][0],&fun[i][1]);
		if(op==2)
			scanf("%lld",&mul[i]);
		if(op==3)
		{
			scanf("%lld",&c);
			for(int j=1;j<=c;j++)
			{
				scanf("%d",&g);
				edge[i].push_back(g);
				in[g]++;
			}
		}
	}
	scanf("%lld",&q);
	for(int i=1;i<=q;i++)
	{
		int func;
		scanf("%d",&func);
		edge[0].push_back(func);
		in[func]++;
	}
	f[0]=mul[0]=1;
	dfs(0);
	topo();
	for(int i=1;i<=n;i++)
		a[i]=a[i]*mul[0]%mod;
	for(int i=1;i<=m;i++)
		if(fun[i][0])
			a[fun[i][0]]=(a[fun[i][0]]+f[i]*fun[i][1]%mod)%mod;
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
	return 0;
}