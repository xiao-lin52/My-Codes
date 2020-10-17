#include<cstdio>
#include<algorithm>
using namespace std;
struct cloud
{
	int x;
	int y;
	int l;
};
bool cmp(cloud a,cloud b)
{
	return a.l<b.l;
}
cloud a[10001];
int n,m,k,s,ans,f[1001];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l);
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int t1=find(a[i].x),t2=find(a[i].y);
		if(t1!=t2)
		{
			f[t1]=f[t2];
			s++;
			ans+=a[i].l;
		}
		if(s==n-k)
		{
			printf("%d",ans);
			return 0;
		}
	}
	printf("No Answer!");
	return 0;
}
