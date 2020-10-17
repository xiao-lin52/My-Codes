#include<cstdio>
using namespace std;
int m,n,v,ans,chess[101][101],visit[101][101],min[101][101],next[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
void dfs(int x,int y,int sum,int p)
{
	int nx,ny;
	if(x==m&&y==m)
	{
		v=1;
		if(sum<ans) ans=sum;
	}
	else
		if(sum<min[x][y])
		{
			min[x][y]=sum;
			for(int i=0;i<=3;i++)
			{
				nx=x+next[i][0];
				ny=y+next[i][1];
				if(nx>=1&&nx<=m&&ny>=1&&ny<=m&&!visit[nx][ny])
				{
					if(!(p==1&&chess[nx][ny]==0))
					{
						if(chess[nx][ny]==0)
						{
							chess[nx][ny]=chess[x][y];
							visit[nx][ny]=1;
							dfs(nx,ny,sum+2,1);
							visit[nx][ny]=0;
							chess[nx][ny]=0;
						}
						else
						{
							if(chess[nx][ny]==chess[x][y])
							{
								visit[nx][ny]=1;
								dfs(nx,ny,sum,0);
								visit[nx][ny]=0;
							}
							else
							{
								visit[nx][ny]=1;
								dfs(nx,ny,sum+1,0);
								visit[nx][ny]=0;
							}
						}
					}
				}
			}
		}
}
int main()
{
//	freopen("chess.in","r",stdin);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		chess[x][y]=c+1;
	}
	ans=10000000;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			min[i][j]=10000000;
	dfs(1,1,0,0);
	if(v)
		printf("%d",ans);
	else
		printf("-1");
	return 0;
}
