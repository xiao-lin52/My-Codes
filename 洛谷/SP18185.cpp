#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
int n,m,len,num,a[N],belong[N],l[1010],r[1010];
vector<int> g[1010];
void cxcl(int x)
{
	g[x].clear();
	for(int i=l[x];i<=r[x];i++)
		g[x].push_back(a[i]);
	sort(g[x].begin(),g[x].end());
}
void update(int x,int k)
{
	a[x]=k;
	cxcl(belong[x]);
}
int query(int x,int y,int k)
{
	int sum=0;
	for(int i=x;i<=min(r[belong[x]],y);i++)
		sum+=a[i]>=k;
	if(belong[x]!=belong[y])
	{
		for(int i=belong[x]+1;i<=belong[y]-1;i++)
			sum+=g[i].end()-lower_bound(g[i].begin(),g[i].end(),k);
		for(int i=l[belong[y]];i<=y;i++)
			sum+=a[i]>=k;
	}
	return sum;
}
int main()
{
	scanf("%d",&n);
	len=sqrt(n);
	num=(n-1)/len+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		belong[i]=(i-1)/len+1;
	}
	for(int i=1;i<=num;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=min(i*len,n);
		cxcl(i);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int op,l,r,k;
		scanf("%d",&op);
		if(op)
		{
			scanf("%d%d",&l,&k);
			update(l,k);
		}
		else
		{
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",query(l,r,k));
		}
	}
	return 0;
}
