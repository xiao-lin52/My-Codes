#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,m,n;
int gcd(int x,int y)
{
	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	m=max(max(a,b),c);
	n=min(min(a,b),c);
	printf("%d/%d",n/gcd(m,n),m/gcd(m,n));
	return 0;
}
