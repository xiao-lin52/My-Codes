#include<cstdio>
#include<algorithm>
using namespace std;
struct Edge
{
	int u;
	int v;
	int c;
};
bool cmp(Edge a,Edge b)
{
	return a.c<b.c;
}
Edge a[400001];
int n,m,s,sum,f[400001];
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
	for(int i=0;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int t1=find(a[i].u),t2=find(a[i].v);
		if(t1!=t2)
		{
			s++;
			sum+=a[i].c;
			f[t1]=f[t2];
		}
		if(s==n)
			break;
	}
	printf("%d",sum);
	return 0;
}