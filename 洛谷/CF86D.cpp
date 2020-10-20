#include<bits/stdc++.h>
#define ll long long
#define N 200010
#define K 1000010
using namespace std;
ll n,m,len,l=1,r,num,a[N],cnt[K],belong[N],ans[N];
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
	num+=(2*cnt[a[i]]+1)*a[i];
	cnt[a[i]]++;
}
void del(ll i)
{
	cnt[a[i]]--;
	num-=(2*cnt[a[i]]+1)*a[i];
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	len=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		belong[i]=(i-1)/len+1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&q[i].x,&q[i].y);
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
		printf("%I64d\n",ans[i]);
	return 0;
}
