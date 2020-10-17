#include<cstdio>
using namespace std;
int n,map[40][40],next[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y)
{
	int nx,ny;
	for(int i=0;i<=3;i++)
	{
		nx=x+next[i][0];
		ny=y+next[i][1];
		if(nx>=0&&nx<=n+1&&ny>=0&&ny<=n+1&&!map[nx][ny])
		{
			map[nx][ny]=2;
			dfs(nx,ny);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	map[0][0]=2;
	dfs(0,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",2-map[i][j]);
		printf("\n"); 
	}
	return 0;
}
