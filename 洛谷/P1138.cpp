#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,a[10001]={-1};
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1])
		{
			k--;
			if(k==0)
			{
				printf("%d",a[i]);
				return 0;
			}
		}
	printf("NO RESULT");
	return 0;
}
