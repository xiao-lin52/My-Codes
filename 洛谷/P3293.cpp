#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct SegTree
{
	int ls;
	int rs;
	int data;
};
SegTree tree[N*21];
int n,m,tot,mx,a,rt[N];
void update(int i,int &j,int l,int r,int x)
{
	j=++tot;
	tree[j]=tree[i];
	tree[j].data++;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(x<=mid)
		update(tree[i].ls,tree[j].ls,l,mid,x);
	else
		update(tree[i].rs,tree[j].rs,mid+1,r,x);
}
int query(int i,int j,int l,int r,int x,int y)
{
	int sum=0;
	if(x<=l&&r<=y)
		return tree[j].data-tree[i].data;
	int mid=(l+r)>>1;
	if(x<=mid)
		sum+=query(tree[i].ls,tree[j].ls,l,mid,x,y);
	if(mid+1<=y)
		sum+=query(tree[i].rs,tree[j].rs,mid+1,r,x,y);
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		update(rt[i-1],rt[i],1,N,a);
	}
	for(int i=1;i<=m;i++)
	{
		int b,x,l,r,ans=0;
		scanf("%d%d%d%d",&b,&x,&l,&r);
		for(int j=17;j>=0;j--)
		{
			int s=(((b>>j)&1)^1);
			if(query(rt[l-1],rt[r],1,N,ans+(s<<j)-x,ans+(s<<j)+(1<<j)-1-x))
				ans|=s<<j;
			else
				ans|=(s^1)<<j;
		}
		printf("%d\n",ans^b);
	}
	return 0;
}