#include<bits/stdc++.h>
using namespace std;
int n,m,w,ans,a[100001],sum[100001];
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		int x,b;
		scanf("%d%d",&x,&b);
		a[x]+=b;
		m=max(m,x);
	}
	for(int i=1;i<=m;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=w;i<=m;i++)
		ans=max(ans,sum[i]-sum[i-w]);
	printf("%d",ans);
	return 0;
}
