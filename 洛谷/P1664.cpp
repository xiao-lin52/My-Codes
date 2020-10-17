#include<cstdio>
#include<cmath>
using namespace std;
int sum,point,z,n,a,price[1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<3;i++)
		price[i]=1;
	for(int i=3;i<7;i++)
		price[i]=2;
	for(int i=7;i<30;i++)
		price[i]=3;
	for(int i=30;i<120;i++)
		price[i]=4;
	for(int i=120;i<365;i++)
		price[i]=5;
	for(int i=365;i<1000;i++)
		price[i]=6;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a)
		{
			if(z)
			{
				sum=sum-pow(2,z-1)<0? 0:sum-pow(2,z-1);
				z=0;
			}
			sum++;
			point+=price[sum];
		}
		else
			z++;
	}
	printf("%d",point);
	return 0;
}