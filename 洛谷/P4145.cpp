#include<bits/stdc++.h>
#define min(x,y) (x<y ? x : y)
using namespace std;
typedef long long ll;
const ll N=1e5+10,B=1e3+10;
ll n,m,len,num,a[N],belong[N],l[N],r[N],tag[N],sum[N];
void update(ll x,ll y)
{
	for(ll i=x;i<=min(r[belong[x]],y);i++)
		if(a[i]!=1&&a[i]!=0)
		{
			sum[belong[x]]+=floor(sqrt(a[i]))-a[i];
			a[i]=floor(sqrt(a[i]));
			if(a[i]==1||a[i]==0)
				tag[belong[i]]--;
		}
	if(belong[x]!=belong[y])
	{
		for(ll i=belong[x]+1;i<=belong[y]-1;i++)
			for(ll j=l[i];j<=r[i]&&tag[i];j++)
				if(a[j]!=1&&a[j]!=0)
				{
					sum[i]+=floor(sqrt(a[j]))-a[j];
					a[j]=floor(sqrt(a[j]));
					if(a[j]==1||a[j]==0)
						tag[i]--;
				}
		for(ll i=l[belong[y]];i<=y;i++)
			if(a[i]!=1&&a[i]!=0)
			{
				sum[belong[y]]+=floor(sqrt(a[i]))-a[i];
				a[i]=floor(sqrt(a[i]));
				if(a[i]==1||a[i]==0)
					tag[belong[y]]--;
			}
	}
}
ll query(ll x,ll y)
{
	ll s=0;
	for(ll i=x;i<=min(r[belong[x]],y);i++)
		s+=a[i];
	if(belong[x]!=belong[y])
	{
		for(ll i=belong[x]+1;i<=belong[y]-1;i++)
			s+=sum[i];
		for(ll i=l[belong[y]];i<=y;i++)
			s+=a[i];
	}
	return s;
}
int main()
{
	scanf("%lld",&n);
	len=sqrt(n);
	num=(n-1)/len+1;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		belong[i]=(i-1)/len+1;
		tag[belong[i]]=a[i]==1||a[i]==0 ? tag[belong[i]] : tag[belong[i]]+1;
		sum[belong[i]]+=a[i];
	}
	for(ll i=1;i<=num;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=min(n,i*len);
	}
	scanf("%lld",&m);
	for(ll i=1;i<=m;i++)
	{
		ll op,x,y;
		scanf("%lld%lld%lld",&op,&x,&y);
		if(x>y)
			swap(x,y);
		if(op==0)
			update(x,y);
		else
			printf("%lld\n",query(x,y));
	}
	return 0;
}
