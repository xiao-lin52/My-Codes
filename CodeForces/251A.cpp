#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,d,ans,a[N];
int main()
{
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		int t=lower_bound(a+1,a+i,a[i]-d)-a;
		ans+=1ll*(i-t)*(i-t-1)/2;
	}
	printf("%lld",ans);
	return 0;
}