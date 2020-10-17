#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=sqrt(2*n);i>1;i--)
	{
		if(i%2==0)
		{
			if(n/i+i/2<=n&&n/i+1-i/2>=1&&n%(n/i*2+1)==0)
				printf("%d %d\n",n/i+1-i/2,n/i+i/2);
		}
		else
		{
			if(n/i+i/2<=n&&n/i-i/2>=1&&n%i==0)
				printf("%d %d\n",n/i-i/2,n/i+i/2);
		}
	}
	return 0;
}
