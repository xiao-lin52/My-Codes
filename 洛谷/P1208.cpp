#include<cstdio>
#include<algorithm>
using namespace std;
struct milk
{
	int p;
	int s;
};
bool cmp(milk a,milk b)
{
	if(a.p!=b.p) return a.p<b.p;
	if(a.s!=b.s) return a.s<b.s;
}
milk a[5001];
int n,m,sum,ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i].p,&a[i].s);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
		if(sum+a[i].s<n)
		{
			sum+=a[i].s;
			ans+=a[i].s*a[i].p;
		}
		else
		{
			ans+=(n-sum)*a[i].p;
			break;
		}
	printf("%d",ans);
	return 0;
}
