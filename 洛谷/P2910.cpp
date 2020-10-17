#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
using namespace std;
int n,m,ans,a[10001],dis[101][101];
int main()
{
	memset(dis,0x3f3f3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=m-1;i++)
		ans+=dis[a[i]][a[i+1]];
	printf("%d",ans);
	return 0;
}
