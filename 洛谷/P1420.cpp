#include<cstdio>
using namespace std;
int len=1,ans,n,a[10000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1]+1)
			len++;
		else
		{
			if(len>ans) ans=len;
			len=1;
		}
	}
	printf("%d",ans);
	return 0;
}
