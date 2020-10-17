#include<cstdio>
#include<algorithm>
using namespace std;
struct map
{
	int u;
	int v;
	int c;
};
bool cmp(map a,map b)
{
	return a.c<b.c;
}
map a[10001];
int n,k,s,ans,f[101];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int t;
			scanf("%d",&t);
			if(i>j)
			{
				k++;
				a[k].u=i;
				a[k].v=j;
				a[k].c=t;
			}
		}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++)
	{
		int t1=find(a[i].u),t2=find(a[i].v);
		if(t1!=t2)
		{
			f[t1]=f[t2];
			s++;
			ans+=a[i].c;
		}
		if(s==n-1)
			break;
	}
	printf("%d",ans);
	return 0;
}
