#include<cstdio>
#include<algorithm>
using namespace std;
struct prize
{
	int p;
	long long q;
};
bool cmp(prize x,prize y)
{
	if(x.p!=y.p) return x.p<y.p;
	if(x.q!=y.q) return x.q<y.q;
}
prize a[100001];
long long n,m,k,i,ans;
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=k;i++)
		scanf("%d%lld",&a[i].p,&a[i].q);
	sort(a+1,a+1+k,cmp);
	i=1;
	while(i<=k)
	{
		long long s=0,f=1;
		while(a[i].p==a[i+1].p&&i<=k)
		{
			s+=(a[i+1].q-a[i].q)*f;
			f++;
			i++;
		}
		s+=(n-a[i].q)*f;
		ans=ans>s? ans:s;
		i++;
	}
	printf("%lld",ans);
	return 0;
}
