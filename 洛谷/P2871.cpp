#include<cstdio>
#define max(a,b) a>b?a:b
using namespace std;
int n,m,v[4001],w[4001],opt[13001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&v[i],&w[i]);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=v[i];j--)
			opt[j]=max(opt[j],opt[j-v[i]]+w[i]);
	printf("%d",opt[m]);
	return 0;
}
