#include<cstdio>
#include<algorithm>
using namespace std;
struct road
{
	int u;
	int v;
	int c;
};
bool cmp(road a,road b)
{
	return a.c<b.c;
}
road a[10001];
int n,m,s,ans,f[2001];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int t1=find(a[i].u),t2=find(a[i].v);
		if(t1!=t2)
		{
			f[t1]=f[t2];
			s++;
			ans=a[i].c;
		}
		if(s==n-1)
			break;
	}
	printf("%d",ans); 
	return 0;
}
