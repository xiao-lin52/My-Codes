#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	int r;
	int w1;
	int w2;
};
node tree[4000001];
int n,m,c,ans1,ans2,flag;
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		scanf("%d",&tree[i].w1);
		tree[i].w2=tree[i].w1;
		return;
	}
	build(i*2,l,(l+r)/2);
	build(i*2+1,(l+r)/2+1,r);
	tree[i].w1=max(tree[i*2].w1,tree[i*2+1].w1);
	tree[i].w2=min(tree[i*2].w2,tree[i*2+1].w2);
}
void query(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		ans1=max(ans1,tree[i].w1);
		ans2=min(ans2,tree[i].w2);
		return;
	}
	if(tree[i*2].r>=l)
		query(i*2,l,r);
	if(tree[i*2+1].l<=r)
		query(i*2+1,l,r);
}
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	build(1,1,n);
	for(int i=1;i<=n-m+1;i++)
	{
		ans1=0;
		ans2=1000000;
		query(1,i,i+m-1);
		if(ans1-ans2<=c)
		{
			printf("%d\n",i);
			flag=1;
		}
	}
	if(!flag)
		printf("NONE");
	return 0;
}
