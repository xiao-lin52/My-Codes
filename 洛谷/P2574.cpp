#include<cstdio>
using namespace std;
struct node
{
	int l;
	int r;
	int data;
	int f;
};
node tree[800001];
int n,m;
void push_down(int i)
{
	if(!tree[i].f)
		return;
	tree[i*2].data=tree[i*2].r-tree[i*2].l+1-tree[i*2].data;
	tree[i*2].f^=1;
	tree[i*2+1].data=tree[i*2+1].r-tree[i*2+1].l+1-tree[i*2+1].data;
	tree[i*2+1].f^=1;
	tree[i].f=0;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		scanf("%1d",&tree[i].data);
		return;
	}
	build(i*2,l,(l+r)/2);
	build(i*2+1,(l+r)/2+1,r);
	tree[i].data=tree[i*2].data+tree[i*2+1].data;
}
void update(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=tree[i].r-tree[i].l+1-tree[i].data;
		tree[i].f^=1;
		return;
	}
	push_down(i);
	if(tree[i*2].r>=l)
		update(i*2,l,r);
	if(tree[i*2+1].l<=r)
		update(i*2+1,l,r);
	tree[i].data=tree[i*2].data+tree[i*2+1].data;
}
int query(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
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
		scanf("%d",&op);
		if(op)
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,l,r));
		}
		else
		{
			scanf("%d%d",&l,&r);
			update(1,l,r);
		}
	}
	return 0;
}
