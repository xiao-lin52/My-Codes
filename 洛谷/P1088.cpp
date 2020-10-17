#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[100000];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		next_permutation(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
