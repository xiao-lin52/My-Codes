#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#define PI 3.141592653589793238
using namespace std;
int n;
double a[101][3],p1,p2,p3,r;
int main()
{
	scanf("%d%lf",&n,&r);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i][1],&a[i][2]);
	for(int i=2;i<=n;i++)
		p1+=sqrt((a[i][1]-a[i-1][1])*(a[i][1]-a[i-1][1])+(a[i][2]-a[i-1][2])*(a[i][2]-a[i-1][2]));
	p2=2*r*PI;
	p3=sqrt((a[1][1]-a[n][1])*(a[1][1]-a[n][1])+(a[1][2]-a[n][2])*(a[1][2]-a[n][2]));
	printf("%.2lf",p1+p2+p3);
	return 0;
}
