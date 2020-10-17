#include<cstdio>
#define min(a,b) a<b?a:b
using namespace std;
int n,ans,a[101],dis[101][101];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				dis[i][j]=1000000000;
	for(int i=1;i<=n;i++)
	{
		int ls,rs;
		scanf("%d%d%d",&a[i],&ls,&rs);
		dis[i][ls]=dis[i][rs]=dis[rs][i]=dis[ls][i]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	ans=1000000000;
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int j=1;j<=n;j++)
			s+=dis[j][i]*a[j];
		ans=min(ans,s);
	}
	printf("%d",ans);
	return 0;
}
