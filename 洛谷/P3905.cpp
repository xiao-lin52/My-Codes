#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
using namespace std;
int n,m,d,s,t,dis[101][101][2];
int main()
{
	scanf("%d%d",&n,&m);
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		dis[u][v][0]=dis[v][u][0]=c;
		dis[u][v][1]=dis[v][u][1]=1;
	}
	scanf("%d",&d);
	for(int i=1;i<=d;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		dis[u][v][1]=dis[v][u][1]=2;
	}
	scanf("%d%d",&s,&t);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j][1]==1)
					dis[i][j][0]=dis[j][i][0]=0;
				dis[i][j][0]=dis[j][i][0]=min(dis[i][k][0]+dis[k][j][0],dis[i][j][0]);
			}
	printf("%d",dis[s][t][0]);
	return 0;
}
