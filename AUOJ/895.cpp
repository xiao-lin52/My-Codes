#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
struct rest
{
	ll x;
	ll t;
};
bool cmp1(rest a,rest b) { return a.t<b.t; }
bool cmp2(rest a,rest b) { return a.x<b.x; }
rest a[N],b[N];
ll n,m,k,sum,ans;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
		a[i].x=read(),a[i].t=read();
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++)
		if(sum+a[i].t<=m)
		{
			sum+=a[i].t;
			b[++k]=a[i];
		}
		else
			break;
	sort(b+1,b+1+k,cmp2);
	sum=0;
	for(int i=1;i<=k;i++)
		if(sum+b[i].x-b[i-1].x+b[i].t<=m)
		{
			sum+=b[i].x-b[i-1].x+b[i].t;
			ans++;
		}
		else
			break;
	printf("%lld",ans);
	return 0;
}

