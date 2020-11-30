#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct SegTree
{
	int ls;
	int rs;
	int data;
};
SegTree tree[N*21];
int n,m,tot,ans,rt[N],lst[N];
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
int query(int i,int j,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(x==mid)
		return tree[tree[j].ls].data-tree[tree[i].ls].data;
	if(x<mid)
		return query(tree[i].ls,tree[j].ls,l,mid,x);
	else
		return tree[tree[j].ls].data-tree[tree[i].ls].data+query(tree[i].rs,tree[j].rs,mid+1,r,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		update(rt[i-1],rt[i],0,n,lst[a]);
		lst[a]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+ans)%n+1;
		y=(y+ans)%n+1;
		if(x>y)
			swap(x,y);
		printf("%d\n",ans=query(rt[x-1],rt[y],0,n,x-1));
	}
	return 0;
}