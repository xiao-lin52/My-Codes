#include<cstdio>
using namespace std;
int main()
{
	int i,n,a[101],b[101];
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=n-i;
	}
	for(i=0;i<=n;i++)
		if(a[i]!=0)
		{
			if(i!=0)
				if(a[i]>0)
					printf("+");
			if(a[i]!=1&&a[i]!=-1)
				printf("%d",a[i]);
			else
				if(a[i]==-1&&b[i]!=0)
					printf("-");
			if(a[i]==1&&b[i]==0)
				printf("1");
			if(a[i]==-1&&b[i]==0)
				printf("-1");
			if(b[i]!=0)
			{
				if(b[i]!=1)
				printf("x^%d",b[i]);
				else
				printf("x");
			}	
		}
	return 0;
}
