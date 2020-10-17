#include<bits/stdc++.h>
#define N 50010
#define ll long long
using namespace std;
int n,len,belong[N],l[N],r[N];
ll a[N],tag[N],sum[N];
void update(int x,int y,ll k)
{
	if(belong[x]==belong[y])
	{
		for(int i=x;i<=y;i++)
			a[i]+=k;
		sum[belong[x]]+=k*(y-x+1);
		return;
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
		tag[i]+=k;
	for(int i=x;i<=r[belong[x]];i++)
		a[i]+=k;
	for(int i=l[belong[y]];i<=y;i++)
		a[i]+=k;
	sum[belong[x]]+=k*(r[belong[x]]-x+1);
	sum[belong[y]]+=k*(y-l[belong[y]]+1);
}
ll query(int x,int y,ll k)
{
	ll s=0;
	k++;
	if(belong[x]==belong[y])
	{
		for(int i=x;i<=y;i++)
			s=(s+a[i]+tag[belong[i]])%k;
		return s;
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
		s=(s+sum[i]+tag[i]*(r[i]-l[i]+1)%k)%k;
	for(int i=x;i<=r[belong[x]];i++)
		s=(s+a[i]+tag[belong[i]])%k;
	for(int i=l[belong[y]];i<=y;i++)
		s=(s+a[i]+tag[belong[i]])%k;
	return s;
}
int main()
{
	scanf("%d",&n);
	len=sqrt(n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=len;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=i*len;
	}
	if(r[len]<n)
	{
		len++;
		l[len]=r[len-1]+1;
		r[len]=n;
	}
	for(int i=1;i<=len;i++)
		for(int j=l[i];j<=r[i];j++)
		{
			belong[j]=i;
			sum[i]+=a[j];
		}
	for(int i=1;i<=n;i++)
	{
		int op,l,r;
		ll c;
		scanf("%d%d%d%lld",&op,&l,&r,&c);
		if(op)
			printf("%lld\n",query(l,r,c));
		else
			update(l,r,c);
	}
	return 0;
}
