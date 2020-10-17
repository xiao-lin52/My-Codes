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
node p[1001];
Edge edge[1000001];
int n,m,k,cnt,s,a[501],f[1001];
double ans;
int find(int x)
{
	return f[x]==x?f[x]:f[x]=find(f[x]);
}
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			++k;
			edge[k].u=i;
			edge[k].v=j;
			edge[k].c=Dis(p[i].x,p[i].y,p[j].x,p[j].y);
		}
	sort(edge+1,edge+1+k,cmp);
	for(int i=1;i<=k;i++)
	{
		int t1=find(edge[i].u),t2=find(edge[i].v);
		if(t1!=t2)
		{
			f[t1]=t2;
			ans=edge[i].c;
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	for(int i=1;i<=m;i++)
		if(a[i]>=ans)
			s++;
	printf("%d",s);
	return 0;
}

