#include<cstdio>
using namespace std;
long double a,sum;
int main()
{
	while(scanf("%Lf",&a)!=EOF)
		sum+=a*1000000;
	printf("%.5Lf",sum/1000000);
	return 0;
}
