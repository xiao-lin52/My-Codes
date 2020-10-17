#include<cstdio>
using namespace std;
double s,x,d,t=7;
int main()
{
	scanf("%lf%lf",&s,&x);
	while(d<s-x)
	{
		d+=t;
		t*=0.98;
	}
	if(d+t>s+x)
		printf("n");
	else
		printf("y");
	return 0;
}
