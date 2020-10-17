#include<cstdio>
#include<cmath>
using namespace std;
struct q
{
	int x;
	int y;
};
q a[250001];
int n,m,l,r,mid,sum,map[501][501],v[501][501],next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int bfs()
{
	int s=0,head=0,tail=1,visit[501][501]={0};
	visit[1][1]=1;
	if(v[1][1])
		s++;
	while(head<tail)
	{
		int nx,ny;
		for(int i=0;i<=3;i++)
		{
			nx=a[head].x+next[i][0];
			ny=a[head].y+next[i][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!visit[nx][ny]&&abs(map[nx][ny]-map[a[head].x][a[head].y])<=mid)
			{
				if(v[nx][ny])
					s++;
				a[tail].x=nx;
				a[tail].y=ny;
				visit[nx][ny]=1;
				tail++;
			}
		}
		head++;
	}
	if(s==sum)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&map[i][j]);
			r=r>map[i][j]? r:map[i][j];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&v[i][j]);
			sum+=v[i][j];
		}
	l=0;
	a[0].x=1;
	a[0].y=1;
	while(l<r)
	{
		mid=(l+r)/2;
		if(bfs())
			r=mid;
		else
			l=mid+1;
	}
	printf("%d",l);
	return 0;
}
