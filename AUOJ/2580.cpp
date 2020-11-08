#include<bits/stdc++.h>
using namespace std;
long long n,ans=1;
int main()
{
	scanf("%lld",&n);
	if(n<6)
		printf("0");
	else
	{
		for(long long i=n;i>=n-6+1;i--)
			ans*=i;
		ans/=720;
		printf("%lld",ans);
	}
	return 0;
}