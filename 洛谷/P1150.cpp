#include<cstdio>
using namespace std;
int n,k,fuck_you,sum;
int main()
{
	scanf("%d%d",&n,&k);
	while(n>0)
	{
		sum+=n;
		int a=n;
		n=(n+fuck_you)/k;
		fuck_you=(a+fuck_you)%k;
	}
	printf("%d",sum);
	return 0;
}
