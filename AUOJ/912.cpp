#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long t,n,m,p[100010];
int main()
{
	p[0]=1;
	scanf("%lld",&t);
	for(int i=1;i<=100000;i++)
		p[i]=p[i-1]*i%mod;
	for(int i=1;i<=t;i++)
	{
		scanf("%lld%lld",&n,&m);
		if(n>m)
			swap(n,m);
		if(m-n>=2)
			printf("0\n");
		else
			if(m-n==1)
				printf("%lld\n",p[n]*p[m]%mod);
			else
				printf("%lld\n",p[n]*p[n]%mod*2%mod);
	}
	return 0;
}
