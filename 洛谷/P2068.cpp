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
void update(int i,int x,int k)
{
	if(tree[i].l==x&&tree[i].r==x)
	{
		tree[i].w+=k;
		return;
	}
	if(tree[i*2].r>=x)
		update(i*2,x,k);
	else
		update(i*2+1,x,k);
	tree[i].w=tree[i*2].w+tree[i*2+1].w;
}
int query(int i,int l,int r)
{
	int s=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].w;
	if(tree[i*2].r>=l)
		s+=query(i*2,l,r);
	if(tree[i*2+1].l<=r)
		s+=query(i*2+1,l,r);
	return s;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		char op;
		int x,y;
		cin>>op>>x>>y;
		if(op=='x')
			update(1,x,y);
		else
			printf("%d\n",query(1,x,y));
	}
	return 0;
}