#include<cstdio>
using namespace std;
int x,n;
long long ans;
int main()
{
	scanf("%d%d",&x,&n);
	for(int i=1;i<=n;i++)
	{
		if(x!=6&&x!=7)
			ans+=250;
		if(x==7)
			x=1;
		else
			x++;
	}
	printf("%lld",ans);
	return 0;
}
