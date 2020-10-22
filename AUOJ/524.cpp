#include<bits/stdc++.h>
#define N 200010
using namespace std;
struct SegTree
{
	int l;
	int r;
	int data;
};
SegTree tree[N<<3];
int h,w,n;
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	tree[i].data=0;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
}
void update(int i,int l,int r)
{
	
}
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++)
	{
		int l;
	}
	return 0;
}