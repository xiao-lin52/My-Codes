#include<cstdio>
using namespace std;
double k,s;
int i;
int main()
{
	scanf("%lf",&k);
	for(i=1;s<=k;i++)
		s+=1.0/i;
	printf("%d",i-1);
	return 0;
}
