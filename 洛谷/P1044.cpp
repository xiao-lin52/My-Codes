#include<cstdio>
using namespace std;
int n,opt[20]={1,1};
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		for(int j=0;j<=i-1;j++)
			opt[i]+=opt[j]*opt[i-1-j];
	printf("%d",opt[n]);
	return 0;
}
