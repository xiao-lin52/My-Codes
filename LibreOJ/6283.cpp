#include<bits/stdc++.h>
#define N 100010
#define mod 10007
using namespace std;
long long n,len,a[N],belong[N],l[N],r[N],add[N],mul[N];
void update_add(long long x,long long y,long long k)
{
	if(belong[x]==belong[y])
	{
		for(long long i=l[belong[x]];i<=r[belong[x]];i++)
			a[i]=(a[i]*mul[belong[i]]%mod+add[belong[i]])%mod;
		for(long long i=x;i<=y;i++)
			a[i]=(a[i]+k)%mod;
		add[belong[x]]=0;
		mul[belong[x]]=1;
		return;
	}
	for(long long i=belong[x]+1;i<=belong[y]-1;i++)
		add[i]=(add[i]+k)%mod;
	for(long long i=l[belong[x]];i<=r[belong[x]];i++)
		a[i]=(a[i]*mul[belong[i]]%mod+add[belong[i]])%mod;
	for(long long i=l[belong[y]];i<=r[belong[y]];i++)
		a[i]=(a[i]*mul[belong[i]]%mod+add[belong[i]])%mod;
	for(long long i=x;i<=r[belong[x]];i++)
		a[i]=(a[i]+k)%mod;
	for(long long i=l[belong[y]];i<=y;i++)
		a[i]=(a[i]+k)%mod;
	add[belong[x]]=add[belong[y]]=0;
	mul[belong[x]]=mul[belong[y]]=1;
}
void update_mul(long long x,long long y,long long k)
{
	if(belong[x]==belong[y])
	{
		for(long long i=l[belong[x]];i<=r[belong[x]];i++)
			a[i]=(a[i]*mul[belong[i]]%mod+add[belong[i]])%mod;
		for(long long i=x;i<=y;i++)
			a[i]=a[i]*k%mod;
		add[belong[x]]=0;
		mul[belong[x]]=1;
		return;
	}
	for(long long i=belong[x]+1;i<=belong[y]-1;i++)
	{
		add[i]=add[i]*k%mod;
		mul[i]=mul[i]*k%mod;
	}
	for(long long i=l[belong[x]];i<=r[belong[x]];i++)
		a[i]=(a[i]*mul[belong[i]]%mod+add[belong[i]])%mod;
	for(long long i=l[belong[y]];i<=r[belong[y]];i++)
		a[i]=(a[i]*mul[belong[i]]%mod+add[belong[i]])%mod;
	for(long long i=x;i<=r[belong[x]];i++)
		a[i]=a[i]*k%mod;
	for(long long i=l[belong[y]];i<=y;i++)
		a[i]=a[i]*k%mod;
	add[belong[x]]=add[belong[y]]=0;
	mul[belong[x]]=mul[belong[y]]=1;
}
long long query(long long x)
{
	return (a[x]*mul[belong[x]]%mod+add[belong[x]])%mod;
}
int main()
{
	scanf("%lld",&n);
	len=sqrt(n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]%=mod;
	}
	for(long long i=1;i<=len;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=i*len;
		mul[i]=1;
	}
	if(r[len]<n)
	{
		len++;
		mul[len]=1;
		l[len]=r[len-1]+1;
		r[len]=n;
	}
	for(long long i=1;i<=len;i++)
		for(long long j=l[i];j<=r[i];j++)
			belong[j]=i;
	for(long long i=1;i<=n;i++)
	{
		long long op,x,y,c;
		scanf("%lld%lld%lld%lld",&op,&x,&y,&c);
		if(op==0)
			update_add(x,y,c);
		if(op==1)
			update_mul(x,y,c);
		if(op==2)
			printf("%lld\n",query(y));
	}
	return 0;
}
