#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
int n,k,ans=0x3f3f3f3f,len,mx,mn,a[N];
int main()
{
	scanf("%d%d",&n,&k);
	len=n-k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=k+1;i++)
	{
		mx=a[i+len-1];
		mn=a[i];
		ans=min(ans,mx-mn);
	}
	printf("%d",ans);
	return 0;
}
