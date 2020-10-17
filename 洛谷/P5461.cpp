#include<cstdio>
#include<cmath>
using namespace std;
int n,a[1200][1200];
int main()
{
	scanf("%d",&n);
	a[1][1]=1;
	for(int i=1;i<pow(2,n);i*=2)
		for(int j=1;j<=i;j++)
			for(int k=1;k<=i;k++)
			{
				a[j][k+i]=a[j][k];
				a[j+i][k]=a[j][k];
				a[j+i][k+i]=0;
			}
	for(int i=pow(2,n);i>=1;i--)
	{
		for(int j=pow(2,n);j>=1;j--)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
