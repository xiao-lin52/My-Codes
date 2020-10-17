#include<cstdio>
#include<cmath>
using namespace std;
bool prime(int n)
{
	for(int j=2;j<=sqrt(n);j++)
		if(n%j==0)
			return false;
	return true;
}
int i,a;
int main()
{
	scanf("%d",&a);
	for(i=2;i<=sqrt(a);i++)
		if(prime(i)&&a%i==0)
		{
			printf("%d",a/i);
			break;
		}
	return 0;
}
