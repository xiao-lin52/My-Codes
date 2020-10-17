#include<cstdio>
using namespace std;
int n,a[101];
int main()
{
	scanf("%d",&n);
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
				a[j]=!a[j];
			printf("%d",a[j]);
		}
		printf("\n");
	}
	return 0;
}
