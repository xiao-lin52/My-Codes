#include<cstdio>
using namespace std;
int r,c,ans,area[101][101],visit[101][101],next[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
void dfs(int x,int y,int step)
{
	int nx,ny;
	if(step>ans)
		ans=step;
	for(int i=0;i<=3;i++)
	{
		nx=x+next[i][0];
		ny=y+next[i][1];
		if(nx>=1&&nx<=r&&ny<=c&&ny>=1&&area[nx][ny]>area[x][y]&&step+1>visit[nx][ny])
		{
			visit[nx][ny]=step+1;
			dfs(nx,ny,step+1);
		}
	}
}
int main()
{
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			scanf("%d",&area[i][j]);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if(!visit[i][j])
				dfs(i,j,1);
	printf("%d",ans);
	return 0;
}
