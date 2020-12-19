//求神 ZJK 保佑我这道题多拿点分 
//求神 LSJ 保佑我这道题多拿点分
//求神 WKR 保佑我这道题多拿点分
//求神 MZX 保佑我这道题多拿点分
//求神 XFY 保佑我这道题多拿点分
#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10,mod=1e9+7;
long long n,k,ans,w[20],p[N][2],pos[20],tmp[20];
long long cal()
{
	long long cnt=0;
	for(long long i=1;i<=k;i++)
		tmp[i]=pos[i];
	while(1)
		for(long long i=1;i<=n;i++)
		{
			tmp[p[i][0]]+=p[i][1];
			cnt=(cnt+1)%mod;
			if(tmp[p[i][0]]<1||tmp[p[i][0]]>w[p[i][0]])
				return cnt;
		}
}
void dfs(long long x)
{
	if(x==k+1)
	{
		ans=(ans+cal())%mod;
		return;
	}
	for(long long i=1;i<=w[x];i++)
	{
		pos[x]=i;
		dfs(x+1);
	}
}
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=k;i++)
		scanf("%lld",&w[i]);
	for(long long i=1;i<=n;i++)
		scanf("%lld%lld",&p[i][0],&p[i][1]);
	dfs(1);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
