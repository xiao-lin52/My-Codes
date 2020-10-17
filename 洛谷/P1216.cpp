#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1001][1001],opt[1001][1001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		opt[n][i]=a[n][i];
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			opt[i][j]=max(opt[i+1][j],opt[i+1][j+1])+a[i][j];
	printf("%d",opt[1][1]);
	return 0;
}
