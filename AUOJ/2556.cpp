#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
bool cmp(ll a,ll b)
{
	return a>b;
}
ll n,m,ans,p,a[N],b[N];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	for(p=1;p<=n&&a[p]<=0;p++)
		ans+=a[p]*b[p];
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=n-p+1;i++)
		ans+=a[i]*b[i];
	printf("%lld",ans);
	return 0;
}