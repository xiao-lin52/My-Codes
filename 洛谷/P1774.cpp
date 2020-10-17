#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,a[500001],t[500001];
void Mergesort(int l,int r)
{
	int mid=(l+r)/2;
	if(l==r)
		return;
	Mergesort(l,mid);
	Mergesort(mid+1,r);
	int i=l,j=mid+1,cnt=l;
	while(i<=mid&&j<=r)
		if(a[i]<=a[j])
		{
			t[cnt++]=a[i];
			i++;
		}
		else
		{
			ans+=j-cnt;
			t[cnt++]=a[j];
			j++;
		}
	while(i<=mid)
		t[cnt++]=a[i++];
	while(j<=r)
		t[cnt++]=a[j++];
	for(int i=l;i<=r;i++)
		a[i]=t[i];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	Mergesort(1,n);
	printf("%lld",ans);
	return 0;
}
