#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,maxn,maxx,ans,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		if(a[i]>maxn)
		{
			ans+=maxn*(maxx-i);
			maxn=a[i];
			maxx=i;
		}
	ans+=maxn*maxx;
	printf("%d",ans);
	return 0;
}