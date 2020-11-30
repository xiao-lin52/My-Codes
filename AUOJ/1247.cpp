#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long ll;
const int N=1e7+10;
ll a,b,k,ans,p[N],v[N],prime[N];
void pre()
{
	p[0]=p[1]=1;
	rep(i,2,b)
	{
		if(!p[i])
		{
			prime[++k]=i;
			v[i]=i;
		}
		for(int j=1;j<=k&&prime[j]*i<=b;j++)
		{
			p[i*prime[j]]=1;
			if(v[i]==prime[j])
				v[i*prime[j]]=v[i];
			if(i%prime[j]==0)
				break;
		}
	}
}
int main()
{
	scanf("%lld%lld",&a,&b);
	pre();
	rep(i,a,b)
		if(v[i])
			ans+=v[i];
		else
			ans++;
	printf("%lld",ans);
	return 0;
}