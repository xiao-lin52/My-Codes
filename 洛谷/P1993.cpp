#include<bits/stdc++.h>
#define pii pair<long long,long long>
#define mp(a,b) make_pair(a,b)
#define inf 0x3f3f3f3f
using namespace std;
long long n,m,k,u[20001],v[20001],c[20001],dis[5001];
int main()
{
	scanf("%lld%lld",&n,&m);
	memset(dis,inf,sizeof(dis));
	for(long long i=1;i<=n;i++)
	{
		k++;
		u[k]=0;
		v[k]=i;
		c[k]=0;
	}
	for(long long i=1;i<=m;i++)
	{
		long long op,x,y,z;
		scanf("%lld%lld%lld",&op,&x,&y);
		switch(op)
		{
			case 1:
				scanf("%lld",&z);
				k++;
				u[k]=y;
				v[k]=x;
				c[k]=-z;
				break;
			case 2:
				scanf("%lld",&z);
				k++;
				u[k]=x;
				v[k]=y;
				c[k]=z;
				break;
			case 3:
				k++;
				u[k]=x;
				v[k]=y;
				c[k]=0;
				k++;
				u[k]=y;
				v[k]=x;
				c[k]=0;
				break;
		}
	}
	dis[0]=0;
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=k;j++)
			dis[v[j]]=min(dis[v[j]],dis[u[j]]+c[j]);
	for(long long i=n+1;i<=k;i++)
		if(dis[v[i]]>dis[u[i]]+c[i])
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}