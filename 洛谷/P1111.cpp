#include<cstdio>
#include<algorithm>
using namespace std;
struct road
{
	int x;
	int y;
	int t;
};
bool cmp(road a,road b)
{
	return a.t<b.t;
}
road a[100001];
int n,m,ans,f[1001];
int set_find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=set_find(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		ans=a[i].t;
		if(set_find(a[i].x)!=set_find(a[i].y))
			f[set_find(a[i].x)]=f[set_find(a[i].y)];
		int p=set_find(1),flag=0;
		for(int j=2;j<=n;j++)
			if(set_find(j)!=p)
			{
				flag=1;
				break;
			}
		if(flag)
			ans=a[i].t;
		else
		{
			printf("%d",ans);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
