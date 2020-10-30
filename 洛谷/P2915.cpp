#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans,a[20],c[20],dp[100010][20];
int Abs(int x)
{
	return x>0 ? x : -x;
}
signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<=n-1;i++)
	{
		scanf("%lld",&a[i]);
		c[i]=a[i];
	}
	sort(c,c+n);
	int qwq=unique(c,c+n)-c;
	for(int i=0;i<=n-1;i++)
		a[i]=lower_bound(c,c+qwq,a[i])-c;
	for(int i=0;i<=n-1;i++)
		dp[1<<i][a[i]]=1;
	for(int i=1;i<=(1<<n)-1;i++)
	{
		for(int j=0;j<=n-1;j++)
		{
			if(i&(1<<j))
			{
				for(int l=0;l<=n-1;l++)
				{
					if(j!=l&&(i&(1<<l))&&Abs(c[a[j]]-c[a[l]])>k)
					{
						dp[i][a[j]]+=dp[i^(1<<j)][a[l]];
					}
				}
			}
		}
	}
	for(int i=0;i<=n-1;i++)
		ans+=dp[(1<<n)-1][a[i]];
	printf("%lld",ans);
	return 0;
}