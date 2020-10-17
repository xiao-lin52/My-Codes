#include<cstdio>
using namespace std;
int n,m,k,s,a[11];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i+=m)
	{
		s++;
		for(int j=1;j<=k;j++)
			if(a[j]==i)
				m++;
	}
	printf("%d",s);
	return 0;
}
