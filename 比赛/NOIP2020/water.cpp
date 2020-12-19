//求神 ZJK 保佑我这道题不要挂分
//求神 LSJ 保佑我这道题不要挂分
//求神 WKR 保佑我这道题不要挂分
//求神 MZX 保佑我这道题不要挂分
//求神 XFY 保佑我这道题不要挂分
#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,m,in[N],d[N],ans[N][2];
vector<long long> edge[N];
long long gcd(long long x,long long y)
{
	while(x)
	{
		long long t=x;
		x=y%x;
		y=t;
	}
	return y;
}
inline void qk(long long i)
{
	long long t=gcd(ans[i][0],ans[i][1]);
	ans[i][0]/=t;
	ans[i][1]/=t;
}
void topo()
{
	queue<long long> q;
	for(long long i=1;i<=m;i++)
	{
		ans[i][0]=ans[i][1]=1;
		q.push(i);
	}
	while(q.size())
	{
		long long u=q.front();
		q.pop();
		for(long long i=0;i<edge[u].size();i++)
		{
			long long v=edge[u][i];
			if(!ans[v][1])
			{
				ans[v][0]=ans[u][0];
				ans[v][1]=ans[u][1]*d[u];
			}
			else
			{
				ans[v][0]=1ll*ans[v][0]*ans[u][1]*d[u]+1ll*ans[v][1]*ans[u][0];
				ans[v][1]=1ll*ans[v][1]*ans[u][1]*d[u];
			}
			qk(v);
			in[v]--;
			if(!in[v])
				q.push(v);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		for(long long j=1;j<=d[i];j++)
		{
			long long v;
			scanf("%lld",&v);
			edge[i].push_back(v);
			in[v]++;
		}
	}
	topo();
	for(long long i=1;i<=n;i++)
		if(!d[i])
		{
			qk(i);
			if(ans[i][1]==1)
				printf("%lld\n",ans[i][0]);
			else
				printf("%lld %lld\n",ans[i][0],ans[i][1]);
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
