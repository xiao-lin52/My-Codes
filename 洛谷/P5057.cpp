#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	int r;
	int w;
};
node tree[400001];
int n,m;
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
		return;
	build(i*2,l,(l+r)/2);
	build(i*2+1,(l+r)/2+1,r);
}
void push_down(int i)
{
	tree[i*2].w^=tree[i].w;
	tree[i*2+1].w^=tree[i].w;
	tree[i].w=0;
}
void update(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].w^=1;
		return;
	}
	push_down(i);
	if(tree[i*2].r>=l)
		update(i*2,l,r);
	if(tree[i*2+1].l<=r)
		update(i*2+1,l,r);
}
int query(int i,int x)
{
	if(tree[i].l==x&&tree[i].r==x)
		return tree[i].w;
	push_down(i);
	if(tree[i*2].r>=x)
		return query(i*2,x);
	else
		return query(i*2+1,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			update(1,l,r);
		}
		else
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",query(1,x));
		}
	}
	return 0;
}
