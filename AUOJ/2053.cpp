#include<cstdio>
using namespace std;
int n,ans,vis[6][6],nxt[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char a[6][6];
int check(int x,int y,int step,int p)
{
	if(step==p)
		return 1;
	vis[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int nx=x+nxt[i][0],ny=y+nxt[i][1],t=0;
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!vis[nx][ny]&&a[nx][ny]==')')
			if(check(nx,ny,step+1,p))
			{
				vis[x][y]=0;
				return 1;
			}
	}
	vis[x][y]=0;
	return 0;
}
void dfs(int x,int y,int step)
{
	vis[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int nx=x+nxt[i][0],ny=y+nxt[i][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!vis[nx][ny])
			if(a[nx][ny]=='(')
				dfs(nx,ny,step+1);
			else
				if(step*2>ans&&check(nx,ny,1,step))
					ans=step*2;
	}
	vis[x][y]=0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=n;j++)
			scanf("%c",&a[i][j]);
	}
	if(a[1][1]==')')
	{
		printf("0");
		return 0;
	}
	dfs(1,1,1);
	printf("%d",ans);
	return 0;
}

