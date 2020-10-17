#include<cstdio>
using namespace std;
int a,b,c,d;
int gcd(int x,int y)
{
	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
}
int main()
{
	scanf("%d/%d%d/%d",&a,&b,&c,&d);
	printf("%d %d",b*d/gcd(a*c,b*d),a*c/gcd(a*c,b*d));
	return 0;
}
