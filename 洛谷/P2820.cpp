#include<cstdio>
#include<algorithm>
using namespace std;
struct AC
{
	int u;
	int v;
	int c;
};
bool cmp(AC a,AC b)
{
	return a.c<b.c;
}
AC a[500000];
int n,k,s,ans,f[1001];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c);
		ans+=a[i].c;
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++)
	{
		if(a[i].c)
		{
			int t1=find(a[i].u),t2=find(a[i].v);
			if(t1!=t2)
			{
				s++;
				f[t1]=f[t2];
				ans-=a[i].c;
			}
			if(s==n-1)
			{
				printf("%d",ans);
				break;
			}
		}
	}
	return 0;
}
