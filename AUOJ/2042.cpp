#include<bits/stdc++.h>
using namespace std;
int n,m;
double dis[1001][1001];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%lf",&dis[i][j]);
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=max(dis[i][j],dis[i][k]*dis[k][j]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%.3lf\n",dis[u][v]);
		}
	}
	return 0;
}

