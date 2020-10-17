#include<cstdio>
using namespace std;
long long a1,a2,a3,n;
int main()
{
	scanf("%ld%ld%ld",&a1,&a2,&n);
	a3=a1+(n-1)*(a2-a1);
	printf("%ld",(a1+a3)*n/2);
	return 0;
}
