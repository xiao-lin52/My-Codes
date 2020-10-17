#include<cstdio>
#include<algorithm>
using namespace std;
struct photo
{
	int qz;
	int index;
};
bool cmp(photo a,photo b)
{
	if(a.qz!=b.qz) return a.qz>b.qz;
	if(a.index!=b.index) return a.index<b.index;
}
photo a[20001];
int n,k,e[11];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=10;i++)
		scanf("%d",&e[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].qz);
		a[i].index=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		a[i].qz+=e[(i-1)%10+1];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=k;i++)
		printf("%d ",a[i].index);
	return 0;
}
