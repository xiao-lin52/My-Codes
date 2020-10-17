#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,l,r,mid;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		if(pow(i,m)<=n)
			ans++;
		else
			break;
	printf("%lld",ans);
	return 0;
}
