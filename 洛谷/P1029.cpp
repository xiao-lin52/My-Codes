#include<cstdio>
using namespace std;
int x,y;
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int devide(int a)
{
	int sum=0;
	for(int i=1;i<=a;i++)
		if(a%i==0&&gcd(a/i,i)==1)
			sum++;
	return sum;
}
int main()
{
	scanf("%d%d",&x,&y);
	if(y%x==0)
		printf("%d",devide(y/x));
	else
		printf("0");
	return 0;
}
