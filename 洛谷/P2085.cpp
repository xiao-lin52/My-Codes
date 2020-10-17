#include<bits/stdc++.h>
#define p pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
priority_queue< p,vector<p>,greater<p> > h;
int n,m,a[10001],b[10001],c[10001],x[10001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		h.push(mp(a[i]+b[i]+c[i],i));
		x[i]++;
	}
	for(int i=1;i<=m;i++)
	{
		p t=h.top();
		int j=t.second;
		h.pop();
		printf("%d ",t.first);
		x[j]++;
		h.push(mp(a[j]*x[j]*x[j]+b[j]*x[j]+c[j],j));
	}
	return 0;
}