//求神 ZJK 保佑我这道题多拿点分 
//求神 LSJ 保佑我这道题多拿点分
//求神 WKR 保佑我这道题多拿点分
//求神 MZX 保佑我这道题多拿点分
//求神 XFY 保佑我这道题多拿点分
#include<bits/stdc++.h>
using namespace std;
const long long N=9e5+10;
long long n,m,lmt,u[N],v[N];
vector<long long> b[100];
long long check(long long i)
{
	if(b[i].size()!=0&&b[i].size()!=m)
		return 0;
	for(long long j=1;j<b[i].size();j++)
		if(b[i][j]!=b[i][j-1])
			return 0;
	return 1;
}
long long dfs(long long step)
{
	if(step==lmt)
	{
		for(long long i=1;i<=n+1;i++)
			if(!check(i))
				return 0;
		return 1;
	}
	for(long long i=1;i<=n+1;i++)
		if(!check(i)&&b[i].size()>0)
		{
			for(long long j=1;j<=n+1;j++)
			{
				if(b[j].size()<m&&i!=j)
				{
					u[step]=i;
					v[step]=j;
					b[j].push_back(b[i][b[i].size()-1]);
					b[i].pop_back();
					if(dfs(step+1))
						return 1;
					b[i].push_back(b[j][b[j].size()-1]);
					b[j].pop_back();
				}
			}
		}
	return 0;
}
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
		{
			long long a;
			scanf("%lld",&a);
			b[i].push_back(a);
		}
	for(lmt=1;lmt<=820000;lmt++)
		if(dfs(0))
		{
			printf("%lld",lmt);
			for(long long i=0;i<=lmt-1;i++)
				printf("\n%lld %lld",u[i],v[i]);
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
