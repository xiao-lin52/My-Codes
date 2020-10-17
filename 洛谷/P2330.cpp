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
road a[100001];
int n,m,s,f[301];
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
		}
		int t=find(1),flag=1;
		for(int j=2;j<=n;j++)
			if(find(j)!=t)
			{
				flag=0;
				break;
			}
		if(flag)
		{
			printf("%d %d",s,a[i].c);
			return 0;
		}
	}
	return 0;
}