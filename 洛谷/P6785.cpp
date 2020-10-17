#include<bits/stdc++.h>
using namespace std;
long long n,k,maxn,ans,flag,sum[1000001];
int main()
{
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		sum[a]+=b;
		maxn=max(maxn,a);
	}
	for(long long i=0;i<=maxn-k;i++)
		if(k)
		{
			if(sum[i]&&sum[i+k])
			{
				ans=max(ans,(2*i+k)*min(sum[i],sum[i+k]));
				flag=1;
			}
		}
		else
		{
			if(sum[i]>=2)
			{
				ans=max(ans,i*sum[i]);
				flag=1;
			}
		}
	if(flag)
		printf("%lld",ans);
	else
		printf("NO");
	return 0;
}
