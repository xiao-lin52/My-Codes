#include<cstdio>
using namespace std;
int n,m,opt[40][40];
int main()
{
	scanf("%d%d",&n,&m);
	opt[0][1]=opt[0][n+1]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			opt[i][j]=opt[i-1][j-1]+opt[i-1][j+1];
		opt[i][0]=opt[i][n];
		opt[i][n+1]=opt[i][1];
	}
	printf("%d",opt[m][1]);
	return 0;
}
