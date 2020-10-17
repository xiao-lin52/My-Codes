#include<cstdio>
using namespace std;
int n,m,i,j,k,l,b[102][102];
char a[102][102];
const char S='?';
const char D='*';
int main()
{
	scanf("%d%d",&n,&m);
	getchar();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			scanf("%c",&a[i][j]);
		getchar();
	}
	for(i=0;i<=m;i++)
		a[0][i]=a[n+1][i+1]=S;
	for(i=0;i<=n;i++)
		a[i][m+1]=a[i+1][0]=S;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]==S)
				for(k=-1;k<=1;k++)
					for(l=-1;l<=1;l++)
						if(a[i+k][j+l]==D) b[i][j]++;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]!=D)
				printf("%d",b[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}
