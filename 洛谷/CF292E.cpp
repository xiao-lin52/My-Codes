#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct lazy_tag
{
	int l;
	int r;
	int lw;
	int rw;
};
struct node
{
	int l;
	int r;
	lazy_tag f;
};
node tree[4*MAXN];
int n,m,a[MAXN],b[MAXN];
void push_down(int i)
{
	int l=i<<1,r=i<<1|1;
	if(tree[l].r>=tree[i].f.l)
	{
		tree[l].f.l=tree[i].f.l;
		tree[l].f.lw=tree[i].f.lw;
		if(tree[l].r>=tree[i].f.r)
		{
			tree[l].f.r=tree[i].f.r;
			tree[l].f.rw=tree[i].f.rw;
		}
		else
		{
			tree[l].f.r=tree[l].r;
			tree[l].f.rw=tree[i].f.rw-(tree[i].f.r-tree[l].r);
		}
	}
	if(tree[r].l<=tree[i].f.r)
	{
		tree[r].f.r=tree[i].f.r;
		tree[r].f.rw=tree[i].f.rw;
		if(tree[r].l<=tree[i].f.l)
		{
			tree[r].f.l=tree[i].f.l;
			tree[r].f.lw=tree[i].f.lw;
		}
		else
		{
			tree[r].f.l=tree[r].l;
			tree[r].f.lw=tree[i].f.lw+(tree[r].l-tree[i].f.l);
		}
	}
	tree[i].f.l=tree[i].f.r=tree[i].f.lw=tree[i].f.rw=0;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
		return;
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
}
void update(int i,int l,int r,int lw,int rw)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].f.l=tree[i].l;
		tree[i].f.r=tree[i].r;
		tree[i].f.lw=lw+(tree[i].l-l);
		tree[i].f.rw=rw-(r-tree[i].r);
		return;
	}
	if(tree[i].f.l)
		push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,lw,rw);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,lw,rw);
}
int query(int i,int x)
{
	if(tree[i].l==x&&tree[i].r==x)
	{
		if(tree[i].f.lw)
			return a[tree[i].f.lw];
		else
			return b[x];
	}
	if(tree[i].f.l)
		push_down(i);
	if(tree[i<<1].r>=x)
		return query(i<<1,x);
	else
		return query(i<<1|1,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x,y,k;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d",&x,&y,&k);
			update(1,y,y+k-1,x,x+k-1);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(1,x));
		}
	}
	return 0;
}
