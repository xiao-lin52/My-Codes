#include<cstdio>
#include<cmath>
#define inf 1e20
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
double cal(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
struct node
{
	int x;
	int y;
};
node a[151];
int n,map[151][151];
double dis[151][151],maxdis[151],l1,l2=inf,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=inf;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%1d",&map[i][j]);
			if(map[i][j])
				dis[i][j]=cal(a[i].x,a[i].y,a[j].x,a[j].y);
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(dis[i][j]!=inf&&i!=j)
				maxdis[i]=max(maxdis[i],dis[i][j]);
		l1=max(l1,maxdis[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(dis[i][j]==inf&&i!=j)
				l2=min(l2,maxdis[i]+maxdis[j]+cal(a[i].x,a[i].y,a[j].x,a[j].y));
	ans=max(l1,l2);
	printf("%.6lf",ans);
	return 0;
}
