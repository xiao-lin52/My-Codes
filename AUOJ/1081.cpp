#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,ans=inf,a[110][110],vis[110][110],mn[110][110],nxt[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y,int cost,int f)
{
	if(x==n&&y==n)
	{
		ans=min(ans,cost);
		return;
	}
	if(cost>=mn[x][y])
		return;
	mn[x][y]=cost;
	vis[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int nx=x+nxt[i][0],ny=y+nxt[i][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!vis[nx][ny])
		{
			if(f&&a[nx][ny]!=2)
			{
				int t=a[x][y];
				a[x][y]=2;
				if(a[nx][ny]!=t)
					dfs(nx,ny,cost+1,0);
				else
					dfs(nx,ny,cost,0);
				a[x][y]=t;
			}
			if(!f)
			{
				if(a[nx][ny]==2)
				{
					a[nx][ny]=a[x][y];
					dfs(nx,ny,cost+2,1);
					a[nx][ny]=2;
				}
				else
					if(a[nx][ny]!=a[x][y])
						dfs(nx,ny,cost+1,0);
					else
						dfs(nx,ny,cost,0);
			}
		}
	}
	vis[x][y]=0;
}
int main()
{
	memset(mn,inf,sizeof(mn));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=2;
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c;
	}
	dfs(1,1,0,0);
	if(ans!=inf)
		printf("%d",ans);
	else
		printf("-1");
	return 0;
}