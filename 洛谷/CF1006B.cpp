#include<bits/stdc++.h>
using namespace std;
struct qwq
{
	int index;
	int s;
};
bool cmp(qwq a,qwq b)
{
	return a.s>b.s;
}
qwq a[2001];
int n,k,s,b[2001];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].s);
		a[i].index=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=k;i++)
	{
		b[i]=a[i].index;
		s+=a[i].s;
	}
	printf("%d\n",s);
	sort(b+1,b+1+k);
	for(int i=1;i<=k-1;i++)
		printf("%d ",b[i]-b[i-1]);
	printf("%d",n-b[k-1]);
	return 0;
}
