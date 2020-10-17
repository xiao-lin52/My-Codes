#include<cstdio>
using namespace std;
int n,m,s,x=1,y=1,a[41][41],next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	s=a[1][1];
	while(x!=n||y!=m)
	{
		int mx,my,maxn=0;
		a[x][y]=0;
		for(int i=0;i<=3;i++)
		{
			int nx,ny;
			nx=x+next[i][0];
			ny=y+next[i][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&maxn<a[nx][ny])
			{
				maxn=a[nx][ny];
				mx=nx;
				my=ny;
			}
		}
		x=mx;
		y=my;
		s+=a[x][y];
	}
	printf("%d",s);
	return 0;
}
