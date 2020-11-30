#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,k,l,r,a[N];
int check(int w)
{
	priority_queue<int> q[2];
	register int ans=0,sum=0,num=n,t=0;
	for(int i=1;i<=n;i++)
		q[0].push(a[i]);
	while(num)
	{
		while(q[t].size())
		{
			while(q[t].size()&&sum+q[t].top()<=w)
			{
				sum+=q[t].top();
				num--;
				q[t].pop();
			}
			while(q[t].size()&&sum+q[t].top()>w)
			{
				q[t^1].push(q[t].top());
				q[t].pop();
			}
		}
		ans++;
		sum=0;
		t^=1;
	}
	if(ans<=k)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		r+=a[i];
		l=max(l,a[i]);
	}
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d",l);
	return 0;
}