#include<cstdio>
#include<algorithm>
using namespace std;
struct water
{
	int num;
	int index;
};
bool cmp(water a,water b)
{
	if(a.num!=b.num) return a.num<b.num;
	if(a.index!=b.index) return a.index<b.index;
}
water t[1001];
int n,ans[1001];
double sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i].num);
		t[i].index=i;
	}
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;i++)
		printf("%d ",t[i].index);
	for(int i=1;i<=n;i++)
		sum+=t[i].num*(n-i);
	printf("\n%.2lf",sum/n);
	return 0;
}
