#include<cstdio>
using namespace std;
int n,m;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		if(m%2)
			printf("zs wins\n");
		else
			printf("pb wins\n");
	}
	return 0;
}
