#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define N 200010
using namespace std;
int n,sum,ans,cnt[N],dep[N],a[N];
vector<pii> edge[N];
void dfs(int u,int fa,int cost)
{
	cnt[u]=cost;
	dep[u]=dep[fa]+1;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i].first,p=edge[u][i].second;
		if(v!=fa)
		{
			sum+=p;
			dfs(v,u,cost+p);
		}
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		sum=0;
		ans=0x3f3f3f3f;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			edge[i].clear();
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			edge[x].push_back(mp(y,0));
			edge[y].push_back(mp(x,1));
		}
		dep[0]=-1;
		dfs(1,0,0);
		for(int i=1;i<=n;i++)
			a[i]=sum-cnt[i]+(dep[i]-cnt[i]);
		for(int i=1;i<=n;i++)
			ans=min(ans,a[i]);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			if(a[i]==ans)
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}
