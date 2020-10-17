#include<cstdio>
#include<cmath>
#include<algorithm>
#define Dis(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
using namespace std;
struct node
{
	double x;
	double y;
};
struct Edge
{
	int u;
	int v;
	double c;
};
bool cmp(Edge a,Edge b)
{
	return a.c<b.c;
}
Edge edge[250001];
node a[501];
int s,p,m,cnt,f[501];
double ans;
int find(int x)
{
	return f[x]==x? f[x]:f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&s,&p);
	for(int i=1;i<=p;i++)
		f[i]=i;
	for(int i=1;i<=p;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=1;i<=p;i++)
		for(int j=1;j<=p;j++)
		{
			m++;
			edge[m].u=i;
			edge[m].v=j;
			edge[m].c=Dis(a[i].x,a[i].y,a[j].x,a[j].y);
		}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int t1=find(edge[i].u),t2=find(edge[i].v);
		if(t1!=t2)
		{
			f[t1]=t2;
			ans=edge[i].c;
			cnt++;
		}
		if(cnt==p-s)
			break;
	}
	printf("%.2lf",ans);
	return 0;
}