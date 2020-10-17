#include<cstdio>
#include<cstring>
using namespace std;
int direction(int a,int b)
{
	if(a==b)
		return 0;
	if(b-a==2||a-b==2)
		return 2;
	return 1;
}
int _abs(int n)
{
	if(n>=0)
		return n;
	else
		return 0-n;
}
struct bfs
{
	int x;
	int y;
	int s;
	int d;
};
bfs a[1000000];
int n,m,ex,ey,head,tail,p,map[60][60],visit[60][60],next[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char dir;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int t;
			scanf("%d",&t);
			if(t)
				map[i][j]=map[i+1][j]=map[i][j+1]=map[i+1][j+1]=1;
		}
	scanf("%d%d%d%d%*c%c",&a[0].x,&a[0].y,&ex,&ey,&dir);
	a[0].x+=1;
	a[0].y+=1;
	ex+=1;
	ey+=1;
	memset(visit,1,sizeof(visit));
	a[0].s=0;
	visit[a[0].x][a[0].y]=0;
	switch(dir)
	{
		case 'N':
			a[0].d=0;
			break;
		case 'E':
			a[0].d=1;
			break;
		case 'S':
			a[0].d=2;
			break;
		case 'W':
			a[0].d=3;
			break;
	}
	head=0;
	tail=1;
	while(head<tail)
	{
		int nx,ny,sum;
		for(int i=0;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				nx=a[head].x+next[i][0]*j;
				ny=a[head].y+next[i][1]*j;
				sum=direction(a[head].d,i)+1+a[head].s;
				if(a[head].x==ex&&a[head].y==ey)
					p=1;
				else
				{
					if(nx>=2&&nx<=n&&ny>=2&&ny<=m&&sum<visit[nx][ny]&&!map[nx][ny])
					{
						visit[nx][ny]=sum;
						a[tail].x=nx;
						a[tail].y=ny;
						a[tail].d=i;
						a[tail].s=sum;
						tail++;
					}
					if(!(nx>=2&&nx<=n&&ny>=2&&ny<=m&&!map[nx][ny]))
						break;
				}
			}
		}
		head++;
	}
	if(p)
		printf("%d",visit[ex][ey]);
	else
		printf("-1");
	return 0;
}
