#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll t,n,m,ans,p,visit[300010],cnt[100010];
vector<ll> edge[100010];
ll dfs(ll u)
{
	ll sum=1;
	visit[u]=1;
	for(int i=0;i<edge[u].size();i++)
	{
		ll v=edge[u][i];
		if(!visit[v])
			sum+=dfs(v);
	}
	return sum;
}
int main()
{
	t=read();
	while(t--)
	{
		ans=p=0;
		memset(cnt,0,sizeof(cnt));
		memset(visit,0,sizeof(visit));
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
			edge[i].clear();
		for(int i=1;i<=m;i++)
		{
			ll u=read(),v=read();
			cnt[u]++;
			cnt[v]++;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			if(!visit[i])
			{
				ll t=dfs(i);
				if(t>1&&p!=0)
				{
					printf("0\n");
					goto l;
				}
				if(t>1)
					p=1;
			}
		for(int i=1;i<=n;i++)
			for(int j=0;j<edge[i].size();j++)
				ans+=cnt[i]+cnt[edge[i][j]]-2;
		printf("%lld\n",ans/4);
		l:;
	}
	return 0;
}
