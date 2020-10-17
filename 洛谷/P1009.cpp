#include<cstdio>
using namespace std;
int n,jw,w1=1,w2=1,a[10000],ans[10000];
int main()
{
	scanf("%d",&n);
	a[1]=1;
	ans[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=w1;j++)
		{
			a[j]=a[j]*i+jw;
			jw=a[j]/10;
			a[j]%=10;
		}
		while(jw)
		{
			a[++w1]=jw;
			jw=a[w1]/10;
			a[w1]%=10;
		}
		w2=w1;
		jw=0;
		for(int j=1;j<=w1;j++)
		{
			ans[j]=ans[j]+a[j]+jw;
			jw=ans[j]/10;
			ans[j]%=10;
		}
		while(jw)
		{
			a[++w2]=jw;
			jw=a[w2]/10;
			a[w2]%=10;
		}
		jw=0;
	}
	for(int i=w2;i>=1;i--)
		printf("%d",ans[i]);
	return 0;
}
