#include<cstdio>
#include<algorithm>
using namespace std;
int t,m,v[10010],w[10010],opt[100010];
int main()
{
	scanf("%d%d",&t,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&v[i],&w[i]);
	for(int i=1;i<=m;i++)
		for(int j=v[i];j<=t;j++)
			opt[j]=max(opt[j],opt[j-v[i]]+w[i]);
	printf("%d",opt[t]);
	return 0;
}
