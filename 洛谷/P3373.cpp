#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	int r;
	long long w;
	long long add;
	long long mul=1;
};
node tree[400001];
int n,m,p,op,x,y;
long long sum;
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		scanf("%lld",&tree[i].w);
		tree[i].w%=p;
		return;
	}
	build(i*2,l,(l+r)/2);
	build(i*2+1,(l+r)/2+1,r);
	tree[i].w=(tree[i*2].w+tree[i*2+1].w)%p;
}
void down(int i,int l,int r)
{
	int mid=(l+r)/2;
	tree[i*2].w=(tree[i*2].w*tree[i].mul+tree[i].add*(mid-l+1))%p;
	tree[i*2+1].w=(tree[i*2+1].w*tree[i].mul+tree[i].add*(r-mid))%p;
	tree[i*2].mul=(tree[i].mul*tree[i*2].mul)%p;
	tree[i*2+1].mul=(tree[i].mul*tree[i*2+1].mul)%p;
	tree[i*2].add=(tree[i*2].add*tree[i].mul+tree[i].add)%p;
	tree[i*2+1].add=(tree[i*2+1].add*tree[i].mul+tree[i].add)%p;
	tree[i].mul=1;
	tree[i].add=0;
}
void add_interval(int i,int l,int r,int k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].w=(tree[i].w+k*(tree[i].r-tree[i].l+1))%p;
		tree[i].add=(tree[i].add+k)%p;
		return;
	}
	down(i,tree[i].l,tree[i].r);
	if(tree[i*2].r>=l)
		add_interval(i*2,l,r,k);
	if(tree[i*2+1].l<=r)
		add_interval(i*2+1,l,r,k);
	tree[i].w=(tree[i*2].w+tree[i*2+1].w)%p;
}
void mul_interval(int i,int l,int r,int k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].w=(tree[i].w*k)%p;
		tree[i].mul=(tree[i].mul*k)%p;
		tree[i].add=(tree[i].add*k)%p;
		return;
	}
	down(i,tree[i].l,tree[i].r);
	if(tree[i*2].r>=l)
		mul_interval(i*2,l,r,k);
	if(tree[i*2+1].l<=r)
		mul_interval(i*2+1,l,r,k);
	tree[i].w=(tree[i*2].w+tree[i*2+1].w)%p;
}
void search_interval(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		sum=(sum+tree[i].w)%p;
		return;
	}
	down(i,tree[i].l,tree[i].r);
	if(tree[i*2].r>=l)
		search_interval(i*2,l,r);
	if(tree[i*2+1].l<=r)
		search_interval(i*2+1,l,r);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		long long k;
		scanf("%d%d%d",&op,&x,&y);
		switch(op)
		{
			case 1:
				scanf("%lld",&k);
				mul_interval(1,x,y,k);
				break;
			case 2:
				scanf("%lld",&k);
				add_interval(1,x,y,k);
				break;
			case 3:
				sum=0;
				search_interval(1,x,y);
				printf("%lld\n",sum%p);
				break;
		}
	}
	return 0;
}
