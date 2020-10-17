#include<bits/stdc++.h>
#define p pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,s,a[100001],b[100001],v[100001];
priority_queue< p,vector<p>,greater<p> > h;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		h.push(mp(a[i]+b[1],i));
		v[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		p t=h.top();
		h.pop();
		printf("%d ",t.first);
		v[t.second]++;
		h.push(mp(a[t.second]+b[v[t.second]],t.second));
	}
	return 0;
}
