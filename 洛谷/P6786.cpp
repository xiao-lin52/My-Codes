#include<bits/stdc++.h>
using namespace std;
int n,k,a[300001],b[300001];
long long ans,f[300001];
int check(int l,int r,int val)
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(b[mid]==val)
			return mid;
		if(b[mid]>val)
			r=mid-1;
		if(b[mid]<val)
			l=mid+1;
	}
	return -1;
} 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			b[++k]=a[i];
		f[k]+=a[i];
	}
	for(int i=1;i<=k;i++)
	{
		if(b[i]%3==0)
		{
			int t=check(1,i,b[i]/3*2);
			if(t!=-1)
				f[i]+=f[t];
		}
		ans=max(ans,f[i]);
	}
	printf("%lld",ans);
	return 0;
}
