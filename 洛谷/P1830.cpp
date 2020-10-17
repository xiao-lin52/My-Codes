#include<cstdio>
using namespace std;
int n,m,x,y,map[110][110],sum[110][110];
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=x;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int j=x1;j<=x2;j++)
			for(int k=y1;k<=y2;k++)
			{
				map[j][k]=i;
				sum[j][k]++;
			}
	}
	for(int i=1;i<=y;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(sum[a][b])
			printf("Y %d %d\n",sum[a][b],map[a][b]);
		else
			printf("N\n");
	}
	return 0;
}
