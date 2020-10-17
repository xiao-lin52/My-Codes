#include<cstdio>
#include<cmath>
#define min(a,b) a<b?a:b
using namespace std;
int n,m,a[100001],f[100001][21];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i][0]=a[i];
	}
	for(int i=1;i<=log2(n);i++)
	{
		for(int j=1;j<=n-(1<<i)+1;j++)
		{
			f[j][i]=min(f[j][i-1],f[j+(1<<i-1)][i-1]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		scanf("%d%d",&l,&r);
		k=log2(r-l+1);
		printf("%d ",min(f[l][k],f[r-(1<<k)+1][k]));
	}
	return 0;
}
