#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k,ans=inf,u[2010],v[2010],c[2010],dis[60][60];
signed main()
{
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,inf,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
		u[i+m]=v[i];
		v[i+m]=u[i];
		c[i+m]=c[i];
	}
	dis[1][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=2*m;j++)
			for(int l=0;l<=k;l++)
			{
				if(dis[v[j]][l]>dis[u[j]][l]+c[j])
					dis[v[j]][l]=dis[u[j]][l]+c[j];
				if(dis[v[j]][l+1]>dis[u[j]][l]+c[j]/2&&l+1<=k)
					dis[v[j]][l+1]=dis[u[j]][l]+c[j]/2;
			}
	for(int i=0;i<=k;i++)
		ans=min(ans,dis[n][i]);
	printf("%d",ans);
	return 0;
}
