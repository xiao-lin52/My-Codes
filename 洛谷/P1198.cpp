#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	int r;
	int w;
};
node tree[800001];
int n,t,d,cnt;
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
		tree[i].w=k;
		return;
	}
	if(tree[i*2].r>=x)
		update(i*2,x,k);
	if(tree[i*2+1].l<=x)
		update(i*2+1,x,k);
	tree[i].w=max(tree[i*2].w,tree[i*2+1].w);
}
int query(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].w;
	if(tree[i*2].r>=l)
		ans=max(ans,query(i*2,l,r));
	if(tree[i*2+1].l<=r)
		ans=max(ans,query(i*2+1,l,r));
	return ans;
}
int main()
{
	scanf("%d%d",&n,&d);
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		char op;
		int x;
		cin>>op>>x;
		if(op=='A')
		{
			cnt++;
			update(1,cnt,(x+t)%d);
		}
		else
		{
			t=query(1,cnt-x+1,cnt);
			printf("%d\n",t);
		}
	}
	return 0;
}
