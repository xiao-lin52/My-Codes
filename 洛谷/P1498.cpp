#include<cstdio>
#include<cstring>
using namespace std;
int n;
char a[1025][2049];
int _pow(int a,int b)
{
	int s=1;
	for(int i=1;i<=b;i++)
		s*=a;
	return s;
}
int main()
{
	scanf("%d",&n);
	memset(a,' ',sizeof(a));
	a[1][1]='\\';
	a[1][2]='_';
	a[1][3]='_';
	a[1][4]='/';
	a[2][2]='\\';
	a[2][3]='/';
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=_pow(2,i-1);j++)
			for(int k=1;k<=_pow(2,i);k++)
			{
				a[j+_pow(2,i-1)][k+_pow(2,i-1)]=a[j][k+_pow(2,i)]=a[j][k];
			}
	}
	for(int i=_pow(2,n);i>=1;i--)
	{
		for(int j=_pow(2,n+1);j>=1;j--)
			printf("%c",a[i][j]);
		printf("\n");
	}
	return 0;
}
