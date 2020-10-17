#include<cstdio>
using namespace std;
int a[10000],b[10000],g[10000],k[10000],n,x,y,ans=-1;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
	scanf("%d%d",&x,&y);
	for(int i=0;i<n;i++)
		if(a[i]<=x&&a[i]+g[i]>=x&&b[i]<=y&&b[i]+k[i]>=y) ans=i+1;
	printf("%d",ans);
	return 0;
}
