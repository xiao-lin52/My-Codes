#include<bits/stdc++.h>
using namespace std;
int n,t,l,r,mid,a[10001];
int check(int k)
{
	int sum=0,tmp[10001]={0};
	priority_queue< int,vector<int>,greater<int> > q;
	for(int i=1;i<=k;i++)
		q.push(a[i]);
	for(int i=k+1;i<=n;i++)
	{
		int t1=q.top();
		q.pop();
		q.push(t1+a[i]);
	}
	while(q.size())
	{
		sum=max(q.top(),sum);
		q.pop();
		if(sum>t)
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	l=1;
	r=n;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d",r);
	return 0;
}
