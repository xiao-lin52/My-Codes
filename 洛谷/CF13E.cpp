#include<bits/stdc++.h>
#define N 100010
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int n,m,len,num,a[N],l[1010],r[1010],belong[N];
pii g[N];
void update(int x,int k)
{
	a[x]=k;
	for(int i=r[belong[x]];i>=l[belong[x]];i--)
	{
		g[i].first=i+a[i];
		g[i].second=1;
		if(g[i].first<=r[belong[x]])
		{
			g[i].second=g[g[i].first].second+1;
			g[i].first=g[g[i].first].first;
		}
	}
}
int query(int x)
{
	int j=x,b,sum=0;
	while(j<=n)
	{
		sum+=g[j].second;
		b=j;
		j=g[j].first;
	}
	while(b+a[b]<=n)
		b+=a[b];
	printf("%d %d\n",b,sum);
}
int main()
{
	scanf("%d%d",&n,&m);
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
	}
	for(int i=n;i>=1;i--)
	{
		g[i].first=i+a[i];
		g[i].second=1;
		if(g[i].first<=r[belong[i]])
		{
			g[i].second=g[g[i].first].second+1;
			g[i].first=g[g[i].first].first;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int op,x,k;
		scanf("%d%d",&op,&x);
		if(op==1)
			query(x);
		else
		{
			scanf("%d",&k);
			update(x,k);
		}
	}
	return 0;
}