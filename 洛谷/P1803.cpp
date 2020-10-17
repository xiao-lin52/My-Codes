#include<cstdio>
#include<algorithm>
using namespace std;
struct fu_k
{
	int s;
	int e;
};
bool cmp(fu_k a,fu_k b)
{
	if(a.e!=b.e) return a.e<b.e;
	if(a.s!=b.s) return a.s<b.s;
}
fu_k a[1000001];
int n,sum,minn;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].s,&a[i].e);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(a[i].s>=minn)
		{
			minn=a[i].e;
			sum++;
		}
	printf("%d",sum);
	return 0;
}
