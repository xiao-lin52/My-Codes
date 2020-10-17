#include<cstdio>
using namespace std;
int n,a,p,t,sum;
int main()
{
	scanf("%d",&n);
	while(sum<n*n)
	{
		scanf("%d",&a);
		sum+=a;
		for(int i=1;i<=a;i++)
		{
			printf("%d",p);
			t++;
			if(t==n)
			{
				printf("\n");
				t=0;
			}
		}
		p=!p;
	}
	return 0;
}
