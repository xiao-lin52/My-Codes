#include<cstdio>
using namespace std;
char a;
int b1,b2,s;
int main()
{
	scanf("%d",&b1);
	b1%=10000;
	while(scanf("%c",&a)&&a!='\n')
	{
		scanf("%d",&b2);
		b2%=10000;
		if(a=='*')
		{
			b1*=b2;
			b1%=10000;
		}
		if(a=='+')
		{
			s+=b1;
			s%=10000;
			b1=b2;
		}
	}
	s+=b1;
	s%=10000;
	printf("%d",s);
	return 0;
}