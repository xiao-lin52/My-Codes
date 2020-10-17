#include<cstdio>
using namespace std;
int n,m,j,a[1001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&j);
		a[j]++;
		if(a[j]==1)
			m++;
	}
	printf("%d\n",m);
	for(int i=1;i<=1000;i++)
		if(a[i])
			printf("%d ",i);
	return 0;
}
