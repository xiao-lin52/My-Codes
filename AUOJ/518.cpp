#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	int r;
	int w;
};
node tree[800001];
int n,m;
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		scanf("%d",&tree[i].w);
		return;
	}
	build(i*2,l,(l+r)/2);
	build(i*2+1,(l+r)/2+1,r);
	tree[i].w=max(tree[i*2].w,tree[i*2+1].w);
}
void change_point(int i,int l,int k)
{
	if(tree[i].l==tree[i].r)
	{
		tree[i].w=k;
		return;
	}
	if(tree[i*2].l<=l&&tree[i*2].r>=l)
		change_point(i*2,l,k);
	if(tree[i*2+1].l<=l&&tree[i*2+1].r>=l)
		change_point(i*2+1,l,k);
	tree[i].w=max(tree[i*2].w,tree[i*2+1].w);
}
int search_interval(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].w;
	if(tree[i*2].r>=l)
		ans=max(ans,search_interval(i*2,l,r));
	if(tree[i*2+1].l<=r)
		ans=max(ans,search_interval(i*2+1,l,r));
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		char x;
		int a,b;
		cin>>x>>a>>b;
		if(x=='Q')
			printf("%d\n",search_interval(1,a,b));
		else
			change_point(1,a,b);
	}
	return 0;
}
