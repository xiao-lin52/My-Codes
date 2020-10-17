#include<cstdio>
using namespace std;
int n,sum,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int h1,h2;
		scanf("%d%d",&h1,&h2);
		sum=sum+(h1+h2-8);
		ans+=sum;
	}
	printf("%d",ans);
	return 0;
}
