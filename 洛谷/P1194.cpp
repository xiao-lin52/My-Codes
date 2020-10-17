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
Edge p[250001];
int a,b,k,s,sum,f[501];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
		f[i]=i;
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<i;j++)
		{
			int t;
			scanf("%d",&t);
			if(t<=a&&t!=0)
			{
				k++;
				p[k].u=i;
				p[k].v=j;
				p[k].c=t;
			}
		}
		for(int j=i;j<=b;j++)
			scanf("%*d");
	}
	for(int i=1;i<=b;i++)
	{
		k++;
		p[k].u=0;
		p[k].v=i;
		p[k].c=a;
	}
	sort(p+1,p+1+k,cmp);
	for(int i=1;i<=k;i++)
	{
		int t1=find(p[i].u),t2=find(p[i].v);
		if(t1!=t2)
		{
			sum+=p[i].c;
			s++;
			f[t1]=f[t2];
		}
		if(s==b)
			break;
	}
	printf("%d",sum);
	return 0;
}
