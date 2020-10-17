#include<cstdio>
using namespace std;
int n,k,opt[100010]={1};
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k&&j<=i;j++)
			opt[i]+=opt[i-j];
		opt[i]%=100003;
	}
	printf("%d ",opt[n]);
	return 0;
}
