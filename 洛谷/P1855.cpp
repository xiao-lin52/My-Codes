#include<cstdio>
#define max(a,b) a>b? a:b
using namespace std;
int n,m,t,ans,a[201][201],opt[201][201];
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=a[i][0];j--)
			for(int k=t;k>=a[i][1];k--)
				opt[j][k]=max(opt[j][k],opt[j-a[i][0]][k-a[i][1]]+1);
	printf("%d",opt[m][t]);
	return 0;
}