#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
struct Query
{
	ll n;
	ll a;
	ll b;
};
Query q[100010];
ll t,mx,pre[1000010];
int main()
{
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld%lld%lld",&q[i].n,&q[i].a,&q[i].b);
		mx=max(mx,max(q[i].a,q[i].b));
	}
	pre[1]=pre[2]=1;
	for(int i=3;i<=mx;i++)
		pre[i]=(pre[i-1]+pre[i-3])%mod;
	for(int i=1;i<=t;i++)
	{
		if(q[i].a>q[i].b)
			swap(q[i].a,q[i].b);
		if(q[i].a==1&&q[i].b==q[i].n)
			printf("%lld\n",pre[q[i].b-q[i].a+1]);
		else
			if(q[i].a==1||q[i].b==q[i].n)
				printf("%lld\n",pre[q[i].b-q[i].a]);
			else
				printf("%lld\n",pre[q[i].b-q[i].a-1]);
	}
	return 0;
}