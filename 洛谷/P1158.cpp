#include<cstdio>
#include<algorithm>
using namespace std;
struct missil
{
	long long d1;
	long long d2;
};
bool cmp(missil a,missil b)
{
	return a.d1>b.d1;
}
missil dis[100001];
int x1,x2,y1,y2,n;
long long ans,r;
int main()
{
	scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dis[i].d1=(x-x1)*(x-x1)+(y-y1)*(y-y1);
		dis[i].d2=(x-x2)*(x-x2)+(y-y2)*(y-y2);
	}
	sort(dis+1,dis+1+n,cmp);
	ans=dis[1].d1;
	for(int i=2;i<=n;i++)
	{
		if(r<dis[i-1].d2)
			r=dis[i-1].d2;
		ans=min(ans,dis[i].d1+r);
	}
	printf("%lld",ans);
	return 0;
}
