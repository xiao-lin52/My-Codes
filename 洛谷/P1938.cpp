#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d,n,m,f,s,ans=-100000000,u[701],v[701],c[701],dis[701];
int main()
{
	scanf("%d%d%d%d%d",&d,&m,&n,&f,&s);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		u[i]=x;
		v[i]=y;
		c[i]=-d;
	}
	for(int i=m+1;i<=m+f;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		u[i]=x;
		v[i]=y;
		c[i]=z-d;
	}
		memset(dis,0x3f3f3f3f,sizeof(dis));
		dis[s]=-d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m+f;j++)
				dis[v[j]]=min(dis[v[j]],dis[u[j]]+c[j]);
		for(int i=1;i<=m+f;i++)
			if(dis[v[i]]>dis[u[i]]+c[i])
			{
				printf("-1");
				goto l;
			}
		for(int i=1;i<=n;i++)
			ans=max(ans,-dis[i]);
	printf("%d",ans);
	l:;
	return 0;
}