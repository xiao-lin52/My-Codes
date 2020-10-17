#include<cstdio>
using namespace std;
int n,flag,b[1001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		b[a]=1;
	}
	for(int i=1000;i>=0;i--)
	{
		if(flag&&b[i])
		{
			printf("%d\n",i);
			break;
		}
		if(b[i])
			flag=1;
	}
	return 0;
}
