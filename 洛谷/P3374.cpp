#include<cstdio>
#define lowbit(x) x&(-x)
using namespace std;
int n,m,tree[500001];
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
	while(x>=1)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		update(i,x);
	}
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
			update(x,y);
		else
			printf("%d\n",query(y)-query(x-1));
	}
	return 0;
}

