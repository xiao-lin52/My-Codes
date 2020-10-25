#include<bits/stdc++.h>
using namespace std;
long long p,q,x,y;
void exgcd(long long a,long long b)
{
	if(!b)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;
	y=t-a/b*y;
}
int main()
{
	scanf("%lld%lld",&p,&q);
	exgcd(p,q);
	x=(x%q+q)%q;
	printf("%lld",x);
	return 0;
}