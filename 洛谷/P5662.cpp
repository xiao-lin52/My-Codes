#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,p,a[101][101];
int main()
{
//	freopen("souvenir.in","r",stdin);
//	freopen("souvenir.out","w",stdout);
	scanf("%d%d%d",&t,&n,&m);
	for(int i=1;i<=t;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	p=m;
	for(int i=2;i<=t;i++)
	{
		int opt[10100]={0};
		for(int j=1;j<=n;j++)
			for(int k=a[i-1][j];k<=p;k++)
				opt[k]=max(opt[k],opt[k-a[i-1][j]]+a[i][j]-a[i-1][j]);
		p=max(p,opt[p]+p);
	}
	printf("%d",p);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
