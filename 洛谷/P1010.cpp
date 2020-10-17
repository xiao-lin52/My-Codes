#include<cstdio>
#include<cmath>
using namespace std;
int n;
void minecraft(int x)
{
	if(x==0)
		printf("0");
	while(x!=0)
	{
		int i;
		i=log(x)/log(2);
		x-=pow(2,i);
		if(i==1)
			printf("2");
		else
		{
			printf("2(");
			minecraft(i);
			printf(")");
		}
		if(x)
			printf("+");
	}
}
int main()
{
	scanf("%d",&n);
	minecraft(n);
	return 0;
}
