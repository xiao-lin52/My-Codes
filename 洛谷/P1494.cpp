#include<bits/stdc++.h>
#define N 50010
#define ll long long
using namespace std;
ll n,m,len,num,l=1,r,a[N],belong[N],cnt[N],ans[N][2];
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
ll gcd(ll a,ll b)
{
	while(a)
	{
		int t=a;
		a=b%a;
		b=t;
	}
	return b;
}
void add(int i)
{
	if(cnt[a[i]])
		num+=cnt[a[i]];
	cnt[a[i]]++;
}
void del(int i)
{
	cnt[a[i]]--;
	if(cnt[a[i]])
		num-=cnt[a[i]];
}
void print(int i)
{
	int t=gcd(ans[i][0],ans[i][1]);
	printf("%lld/%lld\n",ans[i][0]/t,ans[i][1]/t);
}
int main()
{
	scanf("%lld%lld",&n,&m);
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
		if(q[i].x==q[i].y)
		{
			ans[q[i].id][0]=0;
			ans[q[i].id][1]=1;
			continue;
		}
		while(l<q[i].x)
			del(l++);
		while(l>q[i].x)
			add(--l);
		while(r<q[i].y)
			add(++r);
		while(r>q[i].y)
			del(r--);
		ans[q[i].id][0]=num;
		ans[q[i].id][1]=(q[i].y-q[i].x+1)*(q[i].y-q[i].x)/2;
	}
	for(int i=1;i<=m;i++)
		print(i);
	return 0;
}
