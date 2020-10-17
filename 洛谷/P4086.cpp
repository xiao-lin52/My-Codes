#include<bits/stdc++.h>
#define p pair<double,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
bool cmp(p a,p b)
{
	if(a.first!=b.first)
		return a.first>b.first;
	return a.second<b.second;
}
int n,sum,minn,a[100001];
p k[100001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sum=a[n]+a[n-1];
	minn=min(a[n],a[n-1]);
	for(int i=n-2;i>=1;i--)
	{
		k[i]=mp((sum-minn)*1.0/(n-i-1),i);
		minn=min(minn,a[i]);
		sum+=a[i];
	}
	sort(k+1,k+n-1,cmp);
	printf("%d",k[1].second);
	for(int i=2;k[i].first==k[i-1].first;i++)
		printf("\n%d",k[i].second);
	return 0;
}
