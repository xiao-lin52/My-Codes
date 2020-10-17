#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	int r;
	int w;
	int f;
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
	if(tree[i].f)
	{
		tree[i*2].w=tree[i*2].r-tree[i*2].l+1-tree[i*2].w;
		tree[i*2+1].w=tree[i*2+1].r-tree[i*2+1].l+1-tree[i*2+1].w;
		tree[i].f=0;
		tree[i*2].f^=1;
		tree[i*2+1].f^=1;
	}
}
void update(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].w=tree[i].r-tree[i].l+1-tree[i].w;
		tree[i].f^=1;
		return;
	}
	push_down(i);
	if(tree[i*2].r>=l)
		update(i*2,l,r);
	if(tree[i*2+1].l<=r)
		update(i*2+1,l,r);
	tree[i].w=tree[i*2].w+tree[i*2+1].w;
}
int query(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].w;
	push_down(i);
	if(tree[i*2].r>=l)
		ans+=query(i*2,l,r);
	if(tree[i*2+1].l<=r)
		ans+=query(i*2+1,l,r);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(!op)
			update(1,l,r);
		else
			printf("%d\n",query(1,l,r));
	}
	return 0;
}
