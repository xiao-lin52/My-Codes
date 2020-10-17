#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
vector<pii> edge[3001];
priority_queue< pii,vector<pii>,greater<pii> > q;
int n,m,u[9001],v[9001],b[3001];
long long c[9001],f[3001],dis[3001];
int main()
{
	scanf("%d%d",&n,&m);
	memset(f,inf,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		u[i]=0;
		v[i]=i;
		c[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		u[i+n]=x;
		v[i+n]=y;
		c[i+n]=z;
	}
	f[0]=0;
	for(int i=0;i<=n;i++)
		for(int j=1;j<=n+m;j++)
			f[v[j]]=min(f[v[j]],f[u[j]]+c[j]);
	for(int i=1;i<=n+m;i++)
		if(f[v[i]]>f[u[i]]+c[i])
		{
			printf("-1");
			return 0;
		}
	for(int i=n+1;i<=n+m;i++)
		edge[u[i]].push_back(mp(v[i],c[i]+f[u[i]]-f[v[i]]));
	for(int s=1;s<=n;s++)
	{
		long long ans=0;
		memset(b,0,sizeof(b));
		memset(dis,inf,sizeof(dis));
		dis[s]=0;
		q.push(mp(dis[s],s));
		while(q.size())
		{
			int x=q.top().second,d=q.top().first;
			q.pop();
			if(d>dis[x])
				continue;
			b[x]=1;
			for(int j=0;j<edge[x].size();j++)
			{
				int y=edge[x][j].first,z=edge[x][j].second;
				if(dis[y]>dis[x]+z)
				{
					dis[y]=dis[x]+z;
					q.push(mp(dis[y],y));
				}
			}
		}
		for(long long i=1;i<=n;i++)
			if(i!=s)
				if(dis[i]==inf)
					ans+=i*1000000000;
				else
					ans+=i*(dis[i]+f[i]-f[s]);
		printf("%lld\n",ans);
	}
	return 0;
}
