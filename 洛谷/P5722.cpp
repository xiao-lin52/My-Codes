#include<cstdio>
using namespace std;
int sum(int x)
{
	if(x==1)
		return 1;
	else
		return x+sum(x-1);
}
int n;
int main()
{
	scanf("%d",&n);
	printf("%d",sum(n));
	return 0;
}
