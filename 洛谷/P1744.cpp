#include<cstdio>
#include<cstring>
#include<cmath>
#define min(a,b) a<b?a:b
using namespace std;
struct Point
{
	int x;
	int y;
};
Point a[101];
int n,m,s,t,cnt,h[101],b[101];
double dis[101][101];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		for(int j=1;j<=n;j++)
			dis[i][j]=10000000;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		dis[u][v]=dis[v][u]=sqrt((a[u].x-a[v].x)*(a[u].x-a[v].x)+(a[u].y-a[v].y)*(a[u].y-a[v].y));
	}
	scanf("%d%d",&s,&t);
			for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
	printf("%.2lf",dis[s][t]);
	return 0;
}
