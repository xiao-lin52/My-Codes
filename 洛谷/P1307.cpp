#include<cstdio>
using namespace std;
int a,i,s;
int main()
{
	scanf("%d",&a);
	if(a<0)
	{
		printf("-");
		a=0-a;
	}
	while(a>0)
	{
		s=s*10+a%10;
		a/=10;
	}
	printf("%d",s);
	return 0;
}
