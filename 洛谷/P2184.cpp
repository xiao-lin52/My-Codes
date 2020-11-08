#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct SegTree
{
	int l;
	int r;
	int data;
	int cnt;
	int f;
	int fc;
};
SegTree tree[N<<2];
int n,m;
void push_down(int i)
{
	if(!tree[i].f)
		return;
	tree[i<<1].data+=tree[i].f;
	tree[i<<1|1].data+=tree[i].f;
	tree[i<<1].f+=tree[i].f;
	tree[i<<1|1].f+=tree[i].f;
	tree[i<<1].cnt+=tree[i].f;
	tree[i<<1|1].cnt+=tree[i].fc;
	tree[i].f=tree[i].fc=0;
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
void update(int i,int l,int r,int p)
{
	if(r>tree[i].r)
		tree[i].cnt++;
	tree[i].data++;
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].f++;
		if(r>tree[i].r)
			tree[i].fc++;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,0);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,1);
}
int query(int i,int l,int r)
{
	int ans=0,flag=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
	{
		ans+=query(i<<1,l,r);
		flag++;
	}
	if(tree[i<<1|1].l<=r)
	{
		ans+=query(i<<1|1,l,r);
		flag++;
	}
	if(flag==2)
		ans-=tree[i<<1].cnt;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
			update(1,x,y,0);
		else
			printf("%d\n",query(1,x,y));
	}
	return 0;
}
