#include<cstdio>
using namespace std;
unsigned n,a,b;
int main()
{
	scanf("%u",&n);
	a=n>>16;
	b=n<<16;
	printf("%u",a|b);
	return 0;
}
