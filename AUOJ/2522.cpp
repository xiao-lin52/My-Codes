#include<bits/stdc++.h>
#define pii pair<long long,long long>
#define mp make_pair
#define N 1000010
#define min(a,b) a<b?a:b
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
long long n,m,k,cnt,num,sum,s,dep[N],vis[N],dfn[N],low[N],p[N<<1],cir[N];
vector<pii> edge[N];
void tarjan(long long u,long long fa)
{
	dfn[u]=low[u]=++cnt;
	dep[u]=dep[fa]+1;
	for(long long i=0;i<edge[u].size();i++)
	{
		long long v=edge[u][i].first;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])
				num++;
		}
		else
			if(v!=fa&&low[u]>dfn[v])
			{
				low[u]=dfn[v];
				cir[++s]=dep[u]-dep[v]+1;
			}
	}
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++)
	{
		long long u,v;
		scanf("%lld%lld",&u,&v);
		edge[u].push_back(mp(v,i));
		edge[v].push_back(mp(u,i));
	}
	for(long long i=1;i<=n;i++)
		if(!dfn[i])
		{
			sum++;
			tarjan(i,0);
		}
	sort(cir+1,cir+s+1,cmp);
	if(num>=k)
		printf("%lld",sum+k);
	else
	{
		k-=num;
		sum+=num;
		for(long long i=1;i<=s&&k>=cir[i];i++)
		{
			sum+=cir[i]-1;
			k-=cir[i];
		}
		if(k)
			printf("%lld",sum+k-1);
		else
			printf("%lld",sum+k);
		
	}
	return 0;
}