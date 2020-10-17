#include<iostream>
using namespace std;
int ans,n,m,next[4][2]={{0,1},{1,0},{0,-1},{-1,0}},visit[101][101],map[101][101];
void dfs(int x,int y)
{
	int nx,ny;
	visit[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		nx=x+next[i][0];
		ny=y+next[i][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&map[nx][ny]&&!visit[nx][ny])
			dfs(nx,ny);
	}
}
int main()
{
	char dj;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>dj;
    		map[i][j]=dj-'0';
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!visit[i][j]&&map[i][j])
			{
				dfs(i,j);
				ans++;
			}
	cout<<ans;
	return 0;
}

