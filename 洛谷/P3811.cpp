#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,inv[3000010];
int main()
{
	inv[1]=1;
	scanf("%lld%lld",&n,&p);
	printf("1\n");
	for(int i=2;i<=n;i++)
	{
		inv[i]=(p-p/i)*inv[p%i]%p;
		printf("%lld\n",inv[i]);
	}
	return 0;
}
