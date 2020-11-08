#include<bits/stdc++.h>
using namespace std;
int p,n,a[301];
int main()
{
	scanf("%d%d",&p,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[i]%p==a[j]%p)
			{
				printf("%d",i);
				return 0;
			}
	printf("-1");
	return 0;
}
