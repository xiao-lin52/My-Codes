#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
typedef long long ll;
ll n,m,mn,mx,rp[N],rv[N],p[N],v[N];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
		rp[i]=p[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&v[i]);
		rv[i]=v[i];
	}
	sort(p+1,p+1+n);
	sort(v+1,v+1+n);
	for(int i=1;i<=n;i++)
	{
		mn+=v[i]*p[n-i+1];
		mx+=v[i]*p[i];
	}
	printf("%lld %lld\n",mn,mx);
	for(int i=1;i<=m;i++)
	{
		ll op,x,del;
		scanf("%lld%lld%lld",&op,&x,&del);
		if(op==1)
		{
			ll pos;
			if(del==1)
				pos=upper_bound(p+1,p+1+n,rp[x])-p-1;
			else
				pos=lower_bound(p+1,p+1+n,rp[x])-p;
			p[pos]+=del;
			rp[x]+=del;
			mx+=v[pos]*del;
			mn+=v[n-pos+1]*del;
		}
		else
		{
			ll pos;
			if(del==1)
				pos=upper_bound(v+1,v+1+n,rv[x])-v-1;
			else
				pos=lower_bound(v+1,v+1+n,rv[x])-v;
			v[pos]+=del;
			rv[x]+=del;
			mx+=p[pos]*del;
			mn+=p[n-pos+1]*del;
		}
		printf("%lld %lld\n",mn,mx);
	}
	return 0;
}