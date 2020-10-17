#include<cstdio>
using namespace std;
int n,m,t,sx,sy,fx,fy,ans,visit[10][10],next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y)
{
	int nx,ny;
	for(int i=0;i<=3;i++)
	{
		nx=x+next[i][0];
		ny=y+next[i][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!visit[nx][ny])
		{
			visit[nx][ny]=1;
			if(nx==fx&&ny==fy)
				ans++;
			else
				dfs(nx,ny);
			visit[nx][ny]=0;
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d%d%d",&n,&m,&t,&sx,&sy,&fx,&fy);
	for(int i=1;i<=t;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		visit[x][y]=1;
	}
	visit[sx][sy]=1;
	dfs(sx,sy);
	printf("%d",ans);
	return 0;
}
