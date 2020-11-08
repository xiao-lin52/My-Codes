#include<bits/stdc++.h>
using namespace std;
int n,ans[100][100],pos[1600][2];
int main()
{
	scanf("%d",&n);
	pos[1][0]=1;
	pos[1][1]=n/2+1;
	ans[1][n/2+1]=1;
	for(int i=2;i<=n*n;i++)
	{
		if(pos[i-1][0]==1&&pos[i-1][1]!=n)
		{
			pos[i][0]=n;
			pos[i][1]=pos[i-1][1]+1;
		}
		if(pos[i-1][0]!=1&&pos[i-1][1]==n)
		{
			pos[i][0]=pos[i-1][0]-1;
			pos[i][1]=1;
		}
		if(pos[i-1][0]==1&&pos[i-1][1]==n)
		{
			pos[i][0]=pos[i-1][0]+1;
			pos[i][1]=pos[i-1][1];
		}
		if(pos[i-1][0]!=1&&pos[i-1][1]!=n)
			if(!ans[pos[i-1][0]-1][pos[i-1][1]+1])
			{
				pos[i][0]=pos[i-1][0]-1;
				pos[i][1]=pos[i-1][1]+1;
			}
			else
			{
				pos[i][0]=pos[i-1][0]+1;
				pos[i][1]=pos[i-1][1];
			}
		ans[pos[i][0]][pos[i][1]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}