#include<cstdio>
using namespace std;
double a,b,i,j,l,c=100000000;
int main()
{
	scanf("%lf%lf%lf",&a,&b,&l);
	for(i=1;i<=l;i++)
		for(j=1;j<=l;j++)
			if(i/j>=a/b&&i/j-a/b<c)
				c=i/j-a/b;
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=l;j++)
			if(c==i/j-a/b) break;
		if(c==i/j-a/b) break;
	}
	printf("%.0lf %.0lf",i,j);
}