#include<cstdio>
#include<algorithm>
using namespace std;
int n,s0,s5,a[1001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==5)
			s5++;
		else
			s0++;
	}
	if(s0==0)
		printf("-1");
	else
	{
		for(int i=1;i<=s5-s5%9;i++)
			printf("5");
		if(s5-s5%9==0)
			printf("0");
		else
			for(int i=1;i<=s0;i++)
				printf("0");
	}
	return 0;
}