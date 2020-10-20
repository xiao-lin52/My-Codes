#include<bits/stdc++.h>
#define N 50010
using namespace std;
struct SegTree
{
	int l;
	int r;
	int data;
};
SegTree tree[N<<2];
int t,n,m,a[N];
char op[11];
inline void push_up(int i)
{
	tree[i].data=tree[i<<1].data+tree[i<<1|1].data;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	tree[i].data=a[l];
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	push_up(i);
}
void update(int i,int x,int k)
{
	if(tree[i].l==x&&tree[i].r==x)
	{
		tree[i].data+=k;
		return;
	}
	if(tree[i<<1].r>=x)
		update(i<<1,x,k);
	if(tree[i<<1|1].l<=x)
		update(i<<1|1,x,k);
	push_up(i);
}
int query(int i,int l,int r)
{
	int sum=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	if(tree[i<<1].r>=l)
		sum+=query(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		sum+=query(i<<1|1,l,r);
	return sum;
}
int main()
{
	scanf("%d",&t);
	for(int p=1;p<=t;p++)
	{
		printf("Case %d:\n",p);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,1,n);
		while(~scanf("%s",op)&&strcmp(op,"End"))
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(!strcmp(op,"Add"))
				update(1,l,r);
			if(!strcmp(op,"Sub"))
				update(1,l,-r);
			if(!strcmp(op,"Query"))
				printf("%d\n",query(1,l,r));
		}
	}
	return 0;
}