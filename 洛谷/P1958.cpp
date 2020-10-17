#include<cstdio>
using namespace std;
int map[17][17],next[2][2]={{1,0},{0,1}},ans,n,a,b,x,y;
void dfs(int x,int y)
{
	int nx,ny;
	for(int i=0;i<2;i++)
	{
		nx=x+next[i][0];
		ny=y+next[i][1];
		if(nx>=1&&nx<=a&&ny>=1&&ny<=b&&!map[nx][ny])
		{
			if(nx==a&&ny==b)
				ans++;
			else
				dfs(nx,ny);
		}
	}
}
int main()
{
	scanf("%d%d%d",&b,&a,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&y,&x);
		map[x][y]=1;
	}
	dfs(1,1);
	printf("%d",ans);
	return 0;
}