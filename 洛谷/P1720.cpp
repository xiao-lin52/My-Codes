#include<cstdio>
#include<cmath>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	printf("%.2f",(pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n))/sqrt(5));
	return 0;
}
