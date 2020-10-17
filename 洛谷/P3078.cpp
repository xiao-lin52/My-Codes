#include<bits/stdc++.h>
using namespace std;
long long n,a,b,ans,d;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b);
		d=b-a;
		a=b;
		if(d>0)
			ans+=d;
	}
	printf("%lld",ans);
	return 0;
}
