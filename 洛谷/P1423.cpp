#include<cstdio>
#include<cmath>
using namespace std;
double n,sum;
int i;
int main()
{
	scanf("%lf",&n);
	while(sum<n)
	{
		sum+=2*pow(98/100.0,i);
		i++;
	}
	printf("%d",i);
	return 0;
}
