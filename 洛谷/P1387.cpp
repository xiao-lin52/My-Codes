#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans,a[101][101],opt[101][101];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j])
			{
				opt[i][j]=min(opt[i-1][j-1],min(opt[i-1][j],opt[i][j-1]))+1;
				ans=ans>opt[i][j]? ans:opt[i][j];
			}
	printf("%d",ans);
	return 0;
}
