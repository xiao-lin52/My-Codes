#include<cstdio>
#include<algorithm>
using namespace std;
long long a[50],sum=1,n;
int main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++) sum=sum*(a[i]-i)%1000000007;
	printf("%lld",sum);
	return 0;
}
