#include<cstdio>
using namespace std;
int wo,mum,a;
int main()
{
	for(int i=1;i<=12;i++)
	{
		scanf("%d",&a);
		wo+=300;
		if(wo<a)
		{
			printf("-%d",i);
			return 0;
		}
		else
		{
			mum=mum+(wo-a)/100*100;
			wo=(wo-a)%100;
		}
	}
	mum=int(mum*1.2)+wo;
	printf("%d",mum);
	return 0;
}
