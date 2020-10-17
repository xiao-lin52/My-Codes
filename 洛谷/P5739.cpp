#include<cstdio>
using namespace std;
int n;
long long ans;
int f(int x)
{
	if(x==1)
		return x;
	else
		return x*f(x-1);
}
int main()
{
	scanf("%d",&n);
	printf("%d",f(n));
	return 0;
}
