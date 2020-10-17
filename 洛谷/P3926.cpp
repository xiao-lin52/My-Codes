#include<cstdio>
using namespace std;
int a,c,p,q,r,x,time;
int main()
{
	scanf("%d%d%d%d%d%d",&a,&c,&p,&q,&r,&x);
	while(a<c&&time<=x)
	{
		time+=p;
		a++;
	}
	if(time>x)
	{
		printf("%d",a-1);
		return 0;
	}
	if(time+q<=x)
		time+=q;
	while(time<=x)
	{
		time+=r;
		a++;
	}
	if(time>x)
	{
		printf("%d",a-1);
		return 0;
	}
	printf("%d",a);
	return 0;
}
