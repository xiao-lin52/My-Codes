#include<bits/stdc++.h>
#define ll long long
#define N 50010
using namespace std;
ll n,m,k,len,num,l=1,r,a[N],cnt[N],ans[N],belong[N];
struct Query
{
	ll x;
	ll y;
	ll id;
	bool operator < (Query const &a) const
	{
		return (belong[x]^belong[a.x]) ? belong[x]<belong[a.x] : (belong[x]&1) ? y<a.y : y>a.y;
	}
};
Query q[N];
void add(ll i)
{
	num+=cnt[a[i]]*2+1;
	cnt[a[i]]++;
}
void del(ll i)
{
	cnt[a[i]]--;
	num-=cnt[a[i]]*2+1;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	len=n/sqrt(m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		belong[i]=(i-1)/len+1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q[i].x,&q[i].y);
		q[i].id=i;
	}
	sort(q+1,q+1+m);
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].x)
			del(l++);
		while(l>q[i].x)
			add(--l);
		while(r<q[i].y)
			add(++r);
		while(r>q[i].y)
			del(r--);
		ans[q[i].id]=num;
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
