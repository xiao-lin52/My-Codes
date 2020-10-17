#include<bits/stdc++.h>
using namespace std;
long long a,b,c,sum,ans;
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	if(min(a,b)+c<max(a,b))
		sum=2*(min(a,b)+c);
	else
		sum=a+b+c;
	ans=sqrt(sum);
	for(;(ans+1)*(ans+2)<=sum;ans++);
	for(;ans*(ans+1)>sum;ans--);
	printf("%lld",ans);
	return 0;
}
