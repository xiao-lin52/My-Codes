#include<cstdio>
using namespace std;
int n,m,w[101],opt[101][10001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(w[i]<j)
				opt[i][j]=opt[i-1][j]+opt[i-1][j-w[i]];
			if(w[i]==j)
				opt[i][j]=opt[i-1][j]+1;
			if(w[i]>j)
				opt[i][j]=opt[i-1][j];
		}
	printf("%d",opt[n][m]);
	return 0;
}
