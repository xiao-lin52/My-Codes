#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct SegTree
{
	int l;
	int r;
	int data;
	int fk;
	int fd;
};
SegTree tree[N<<2];
int n,m;
inline void push_down(int i)
{
	tree[i<<1].fk+=tree[i].fk;
	tree[i<<1|1].fk+=tree[i].fk+(tree[i<<1|1].l-tree[i].l)*tree[i].fd;
	tree[i<<1].fd+=tree[i].fd;
	tree[i<<1|1].fd+=tree[i].fd;
	tree[i].fk=tree[i].fd=0;
}
void build(int i,int l,int r)
{
	tree[i]=(SegTree){l,r,0,0};
	if(l==r)
		return (void)scanf("%d",&tree[i].data);
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
}
void update(int i,int l,int r,int k,int d)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].fk+=k+(tree[i].l-l)*d;
		tree[i].fd+=d;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k,d);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k,d);
}
int query(int i,int x)
{
	if(tree[i].l==tree[i].r)
		return tree[i].data+tree[i].fk;
	push_down(i);
	if(tree[i<<1].r>=x)
		return query(i<<1,x);
	else
		return query(i<<1|1,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,l,r,k,d,p;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d%d",&l,&r,&k,&d);
			update(1,l,r,k,d);
		}
		else
		{
			scanf("%d",&p);
			printf("%d\n",query(1,p));
		}
	}
	return 0;
}
