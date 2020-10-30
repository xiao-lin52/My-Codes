#include<bits/stdc++.h>
using namespace std;
struct env
{
	int w;
	int h;
	int id;
};
bool cmp(env a,env b)
{
	if(a.w!=b.w)
		return a.w<b.w;
	return a.h<b.h;
}
env a[5001];
int n,ans,u,flag,dp[5001],pre[5001];
void output(int i)
{
	if(pre[i]==i)
	{
		printf("%d ",a[i].id);
		return;
	}
	output(pre[i]);
	printf("%d ",a[i].id);
}
int main()
{
	scanf("%d%d%d",&n,&a[0].w,&a[0].h);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].w,&a[i].h);
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(a[i].w>a[0].w&&a[i].h>a[0].h)
			dp[i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			if(a[i].w>a[j].w&&a[i].h>a[j].h&&a[j].w>a[0].w&&a[j].h>a[0].h&&dp[i]<dp[j]+1)
			{
				dp[i]=dp[j]+1;
				pre[i]=j;
			}
	for(int i=1;i<=n;i++)
		if(dp[i]>ans)
		{
			ans=dp[i];
			u=i;
		}
	printf("%d\n",ans);
	if(ans)
		output(u);
	return 0;
}
