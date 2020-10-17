#include<cstdio>
using namespace std;
struct queue
{
	int x;
	int y;
};
queue q[1000000];
int visit[21][21],next[2][2]={{1,0},{0,1}},n,m,a,b,head,tail=1;
long long rec[21][21];
void mark(int x,int y)
{
	if(x>=0&&y>=0&&y<=m&&x<=n) visit[x][y]=1;
    if(x-1>=0&&y-2>=0&&y-2<=m&&x-1<=n) visit[x-1][y-2]=1;
    if(x-2>=0&&y-1>=0&&y-1<=m&&x-1<=n) visit[x-2][y-1]=1;
    if(x-2>=0&&y+1>=0&&y+1<=m&&x-2<=n) visit[x-2][y+1]=1;
    if(x-1>=0&&y+2>=0&&y+2<=m&&x-1<=n) visit[x-1][y+2]=1;
    if(x+1>=0&&y-2>=0&&y-2<=m&&x+1<=n) visit[x+1][y-2]=1;
    if(x+2>=0&&y-1>=0&&y-1<=m&&x+2<=n) visit[x+2][y-1]=1;
    if(x+2>=0&&y+1>=0&&y+1<=m&&x+2<=n) visit[x+2][y+1]=1;
    if(x+1>=0&&y+2>=0&&y+2<=m&&x+1<=n) visit[x+1][y+2]=1;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	rec[0][0]=1;
	q[0].x=q[0].y=0;
	mark(a,b);
	while(head<tail)
	{
		for(int j=0;j<=1;j++)
		{
			int nx,ny;
			nx=q[head].x+next[j][0];
			ny=q[head].y+next[j][1];
			rec[nx][ny]+=rec[q[head].x][q[head].y];
			if(nx>=0&&nx<=n&&ny>=0&&ny<=m&&!visit[nx][ny])
			{
				visit[nx][ny]=1;
				q[tail].x=nx;
				q[tail].y=ny;
				tail++;
			}
		}
		head++;
	}
	printf("%lld",rec[n][m]);
	return 0;
}
