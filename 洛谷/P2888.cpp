#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 100000000
using namespace std;
int n,m,t,dis[301][301];
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				dis[i][j]=inf;
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		dis[u][v]=c;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
	for(int i=1;i<=t;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		if(dis[s][t]==inf)
			printf("-1\n");
		else
			printf("%d\n",dis[s][t]);
	}
	return 0;
}
