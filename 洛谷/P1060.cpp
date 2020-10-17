#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,v[25],w[25],opt[25][30000];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&v[i],&w[i]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(j>=v[i])
				opt[i][j]=max(opt[i-1][j],opt[i-1][j-v[i]]+v[i]*w[i]);
			else
				opt[i][j]=opt[i-1][j];
	printf("%d",opt[m][n]);
	return 0;
}
