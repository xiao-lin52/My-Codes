#include<bits/stdc++.h>
#define ll long long
#define N 300010
#define find(x,k) lower_bound(g[x].begin(),g[x].end(),k)-g[x].begin()
using namespace std;
ll n,m,u,len,num,a[N],belong[N],l[1010],r[1010];
vector<ll> g[1010];
void cxcl(ll x)
{
	g[x].clear();
	for(int i=l[x];i<=r[x];i++)
		g[x].push_back(a[i]);
	sort(g[x].begin(),g[x].end());
}
void update(ll x,ll k)
{
	a[x]=k;
	cxcl(belong[x]);
}
ll query(ll x,ll y,ll k)
{
	ll sum=0;
	for(int i=x;i<=min(r[belong[x]],y);i++)
		if(a[i]<k)
			sum++;
	if(belong[x]!=belong[y])
	{
		for(int i=belong[x]+1;i<=belong[y]-1;i++)
			sum+=find(i,k);
		for(int i=l[belong[y]];i<=y;i++)
			if(a[i]<k)
				sum++;
	}
	return sum;
}
int main()
{
	scanf("%d%d%d",&n,&m,&u);
	len=sqrt(n);
	num=(n-1)/len+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		belong[i]=(i-1)/len+1;
	}
	for(int i=1;i<=num;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=min(i*len,n);
		cxcl(i);
	}
	for(int i=1;i<=m;i++)
	{
		ll x,y,v,p;
		scanf("%lld%lld%lld%lld",&x,&y,&v,&p);
		update(p,u*query(x,y,v)/(y-x+1));
	}
	for(int i=1;i<=n;i++)
		printf("%lld\n",a[i]);
	return 0;
}
