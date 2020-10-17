#include<cstdio>

#include<algorithm>

using namespace std;

int n,m,a[201][201],opt[210][210];

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

		{

			scanf("%d",&a[i][j]);

			opt[i][j]=a[i][j];

		}

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			opt[i][j]+=max(opt[i-1][j-1],max(opt[i-1][j],opt[i-1][j+1]));

	printf("%d",max(opt[n][m/2+1],max(opt[n][m/2],opt[n][m/2+2])));

	return 0;

}
