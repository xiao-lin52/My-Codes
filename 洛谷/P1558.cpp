#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct SegTree
{
	int l;
	int r;
	int data;
	int f;
};
SegTree tree[N<<2];
int n,t,q;
int count(int x)
{
	int sum=0;
	for(;x;x-=x&(-x))
		sum++;
	return sum;
}
void push_down(int i)
{
	if(!tree[i].f)
		return;
	tree[i<<1].data=tree[i].f;
	tree[i<<1|1].data=tree[i].f;
	tree[i<<1].f=tree[i].f;
	tree[i<<1|1].f=tree[i].f;
	tree[i].f=0;
}
void build(int i,int l,int r)
{
	tree[i]=(SegTree){l,r,2,0};
	if(l==r)
		return;
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
}
void update(int i,int l,int r,int k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data=1<<k;
		tree[i].f=1<<k;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k);
	tree[i].data=tree[i<<1].data|tree[i<<1|1].data;
}
int query(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans|=query(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		ans|=query(i<<1|1,l,r);
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&t,&q);
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		char op;
		int a,b,c;
		cin>>op;
		scanf("%d%d",&a,&b);
		if(a>b)
			swap(a,b);
		if(op=='C')
		{
			scanf("%d",&c);
			update(1,a,b,c);
		}
		else
			printf("%d\n",count(query(1,a,b)));
	}
	return 0;
}