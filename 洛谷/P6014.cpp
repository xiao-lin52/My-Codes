#include<cstdio>
using namespace std;
int n,sum,b[11];
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d",&a);
		sum+=a;
		b[a]++;
	}
	for(int i=1; i<=10; i++)
		for(int j=1; j<=10; j++)
			if(((i==j&&b[i]>=2)||(i!=j&&b[i]>=1&&b[j]>=1))&&(i+j)%10==sum%10)
			{
				if((i+j)%10==0)
					printf("10");
				else
					printf("%d",(i+j)%10);
				return 0;
			}
	printf("0");
	return 0;
}
