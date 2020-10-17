#include<cstdio>
#include<cmath>
#define inf 1e9
#define Dis(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define min(a,b) a<b?a:b
using namespace std;
struct node
{
	double x;
	double y;
};
node a[5001];
int n,b[5001];
double ans,dis[5001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		double minn=inf;
		int u=0;
		for(int j=1;j<=n;j++)
			if(minn>dis[j]&&!b[j])
			{
				minn=dis[j];
				u=j;
			}
		ans+=dis[u];
		b[u]=1;
		for(int j=1;j<=n;j++)
			dis[j]=min(dis[j],Dis(a[u].x,a[u].y,a[j].x,a[j].y));
	}
	printf("%.2lf",ans);
	return 0;
}
