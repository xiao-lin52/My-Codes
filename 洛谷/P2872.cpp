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
node a[1001];
Edge edge[1000001];
int n,m,k,cnt,f[1001];
double ans;
int find(int x)
{
	return f[x]==x?f[x]:f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int t1=find(u),t2=find(v);
		if(t1!=t2)
		{
			cnt++;
			f[t1]=t2;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(find(i)!=find(j))
			{
				k++;
				edge[k].u=i;
				edge[k].v=j;
				edge[k].c=Dis(a[i].x,a[i].y,a[j].x,a[j].y);
			}
	sort(edge+1,edge+1+k,cmp);
	for(int i=1;i<=k;i++)
	{
		if(cnt==n-1)
			break;
		int t1=find(edge[i].u),t2=find(edge[i].v);
		if(t1!=t2)
		{
			f[t1]=t2;
			ans+=edge[i].c;
			cnt++;
		}
	}
	printf("%.2lf",ans);
	return 0;
}

