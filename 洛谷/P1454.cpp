#include<iostream>
using namespace std;
int n,m,s,map[101][101];
int next[12][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1},{2,0},{0,2},{-2,0},{0,-2}};
void dfs(int x,int y)
{
	map[x][y]=0;
	for(int i=0;i<=11;i++)
	{
		int nx,ny;
		nx=x+next[i][0];
		ny=y+next[i][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&map[nx][ny]==1)
			dfs(nx,ny);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char t;
			cin>>t;
			if(t=='#')
				map[i][j]=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j])
			{
				dfs(i,j);
				s++;
			}
	cout<<s;
	return 0;
}
