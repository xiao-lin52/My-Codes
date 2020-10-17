#include<cstdio>
#include<algorithm>
using namespace std;
int t,m,a[101][2],opt[101][1001];
int main()
{
	scanf("%d%d",&t,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<a[i][0];j++)
			opt[i][j]=opt[i-1][j];
		for(int j=a[i][0];j<=t;j++)
			opt[i][j]=max(opt[i-1][j],opt[i-1][j-a[i][0]]+a[i][1]);
	}
	printf("%d",opt[m][t]);
	return 0;
}
