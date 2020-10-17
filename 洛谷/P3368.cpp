#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
int n,m,a,b,d[500001];
void update(int x,int k)
{
	while(x<=n)
	{
		d[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ans=0;
	while(x)
	{
		ans+=d[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b);
		update(i,b-a);
		a=b;
	}
	for(int i=1;i<=m;i++)
	{
		int op,x,y,k;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d",&x,&y,&k);
			update(x,k);
			update(y+1,-k);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}
