#include<cstdio>
using namespace std;
struct bfs
{
	int x;
	int y;
	int s;
};
bfs a[1600000];
int n,m,sx,sy,head,tail,visit[410][410],ans[410][410];
int next[8][2]={{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};
int main()
{
	scanf("%d%d%d%d",&n,&m,&sx,&sy);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans[i][j]=-1;
	a[0].x=sx;
	a[0].y=sy;
	ans[sx][sy]=0;
	visit[sx][sy]=1;
	head=0;
	tail=1;
	while(head<tail)
	{
		int nx,ny;
		for(int i=0;i<=7;i++)
		{
			nx=a[head].x+next[i][0];
			ny=a[head].y+next[i][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!visit[nx][ny])
			{
				a[tail].x=nx;
				a[tail].y=ny;
				a[tail].s=a[head].s+1;
				visit[nx][ny]=1;
				ans[nx][ny]=a[tail].s;
				tail++;
			}
		}
		head++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%-5d",ans[i][j]);
		printf("\n");
	}
	return 0;
}
