#include<cstdio>
using namespace std;
int n,k;
long long s,m,ans,a[1000001];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		scanf("%lld",&a[i]);
		m+=a[i];
		if(i==k)
			s=m;
	}
	ans=m;
	for(int i=1+k;i<=n;i++)
	{
		if(m-s<ans)
			ans=m-s;
		s=s-a[i-k]+a[i];
	}
	printf("%lld",ans);
	return 0;
}
