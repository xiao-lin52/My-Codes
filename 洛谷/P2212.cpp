#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define Dis(x1,y1,x2,y2) (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)
using namespace std;
struct node
{
	long long x;
	long long y;
};
node a[2001];
long long n,c,ans,cnt,dis[2001],b[2001];
int main()
{
	memset(dis,inf,sizeof(dis));
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].y);
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		long long minn=inf,u=0;
		for(int j=1;j<=n;j++)
			if(dis[j]<minn&&!b[j])
			{
				minn=dis[j];
				u=j;
			}
		if(!u)
		{
			ans=-1;
			break;
		}
		ans+=dis[u];
		b[u]=1;
		for(int j=1;j<=n;j++)
		{
			int d=Dis(a[u].x,a[u].y,a[j].x,a[j].y);
			if(d>=c&&d<dis[j])
				dis[j]=d;
		}
	}
	printf("%lld",ans);
	return 0;
}