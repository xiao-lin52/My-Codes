#include<cstdio>
using namespace std;
int n,a,b,sum,m;
int main()
{
	scanf("%d%d",&n,&a);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&b);
		if(a<b)
			sum++;
		else
			sum=1;
		if(m<sum)
			m=sum;
		a=b;
	}
	printf("%d",m);
	return 0;
}
