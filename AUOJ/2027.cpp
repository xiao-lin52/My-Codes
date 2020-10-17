#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++)
	{
		long long t;
		scanf("%lld",&t);
		sum+=t%m;
		ans+=t/m+sum/m;
		sum%=m;
	}
	ans+=sum/m;
	if(sum%m)
		ans++;
	printf("%lld",ans);
	return 0;
}


