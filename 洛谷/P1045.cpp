#include<cstdio>
#include<cmath>
using namespace std;
int my_pow(int b,int k)
{
	int s=1;
	for(int i=1;i<=k;i++)
		s*=b;
	return s;
}
int n,w=1,jw,a[2000];
int main()
{
	scanf("%d",&n);
	printf("%d\n",int(log10(2)*n+1));
	if(n%2==0)
	{
		a[1]=1;
		n/=2;
	}
	else
	{
		a[1]=2;
		n/=2;
	}
	for(int z=1;z<=n;z++)
	{
		jw=0;
		for(int i=1;i<=w&&i<=100;i++)
		{
			a[i]=a[i]*4+jw;
			jw=a[i]/100000;
			a[i]%=100000;
		}
		if(jw&&w<100)
			a[++w]=jw;
	}
	a[1]-=1;
	for(int i=10;i>=1;i--)
	{
		for(int j=0;j<=9;j++)
			printf("%05d",a[i*10-j]);
		printf("\n");
	}
	return 0;
}
