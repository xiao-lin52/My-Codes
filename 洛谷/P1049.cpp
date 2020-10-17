#include<cstdio>
#include<algorithm>
using namespace std;
int v,n,a[31],opt[31][20001];
int main()
{
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<a[i];j++)
			opt[i][j]=opt[i-1][j];
		for(int j=a[i];j<=v;j++)
			opt[i][j]=max(opt[i-1][j],opt[i-1][j-a[i]]+a[i]);
	}
	printf("%d",v-opt[n][v]);
	return 0;
}
