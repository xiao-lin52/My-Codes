#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
int n,m,op,x,y,tree[10000001];
void update(int x,int k)
{
	while(x<=n)
	{
		tree[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ans=0;
	while(x)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if(!op)
		{
			scanf("%d%d",&x,&y);
			update(x,1);
			update(y+1,-1);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}
