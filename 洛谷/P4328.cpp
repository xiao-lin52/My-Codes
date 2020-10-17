#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct bfs
{
	int x;
	int y;
	int step;
};
bfs a[10000];
int n,m,ex,ey,head,tail=1,f[51][51],visit[51][51];
int next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char map[51][51];
void bfs_flood(int x,int y)
{
	bfs b[10000];
	b[0].x=x;
	b[0].y=y;
	while(head<tail)
	{
		int nx,ny;
		for(int i=0;i<=3;i++)
		{
			nx=b[head].x+next[i][0];
			ny=b[head].y+next[i][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&(map[nx][ny]=='.'||map[nx][ny]=='S')&&b[head].step+1<f[nx][ny])
			{
				b[tail].x=nx;
				b[tail].y=ny;
				b[tail].step=b[head].step+1;
				f[nx][ny]=b[tail].step;
				tail++;
			}
		}
		head++;
	}
}
int main()
{
	cin>>n>>m;
	memset(f,0x3f3f3f,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='S')
				a[0].x=i,a[0].y=j;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j]=='*')
				bfs_flood(i,j);
	head=0;
	tail=1;
	visit[a[0].x][a[0].y]=1;
	while(head<tail)
	{
		int nx,ny;
		for(int i=0;i<=3;i++)
		{
			nx=a[head].x+next[i][0];
			ny=a[head].y+next[i][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&map[nx][ny]!='X'&&map[nx][ny]!='*'&&!visit[nx][ny]&&a[head].step+1<f[nx][ny])
			{
				a[tail].x=nx;
				a[tail].y=ny;
				a[tail].step=a[head].step+1;
				visit[nx][ny]=1;
				if(map[nx][ny]=='D')
				{
					printf("%d",a[tail].step);
					return 0;
				}
				tail++;
			}
		}
		head++;
	}
	printf("KAKTUS");
	return 0;
}
