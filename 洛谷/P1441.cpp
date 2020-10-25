#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
int n,m,ans,sum,vis[30],a[30],dp[2010];
void dfs(int x,int s,int last)
{
	if(x==m)
	{
		int tmp=0;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
				continue;
			for(int j=sum-s;j>=a[i];j--)
			{
				if(dp[j-a[i]]&&!dp[j])
					tmp++;
				dp[j]|=dp[j-a[i]];
			}
		}
		ans=max(ans,tmp);
		return;
	}
	for(int i=last+1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(x+1,s+a[i],i);
			vis[i]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	dfs(0,0,1);
	printf("%d",ans);
	return 0;
}