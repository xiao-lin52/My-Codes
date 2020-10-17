#include<cstdio>

#include<algorithm>

using namespace std;

int n,m,a[110],opt[110][110];

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1; i<=n; i++)

		scanf("%d",&a[i]);

	opt[0][0]=1;

	for(int i=1; i<=n; i++)

		for(int j=0; j<=m; j++)

			for(int k=0; k<=min(j,a[i]); k++)

				opt[i][j]=(opt[i][j]+opt[i-1][j-k])%1000007;

	printf("%d",opt[n][m]);

	return 0;

}
