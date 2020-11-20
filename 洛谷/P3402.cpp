#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct SegTree
{
	int ls;
	int rs;
	int id;
	int data;
	int siz;
};
SegTree tree[21*N];
int n,m,tot,rt[N<<1];
void build(int &i,int l,int r)
{
	i=++tot;
	if(l==r)
	{
		tree[i].data=l;
		tree[i].siz=1;
		tree[i].id=l;
		return;
	}
	int mid=(l+r)>>1;
	build(tree[i].ls,l,mid);
	build(tree[i].rs,mid+1,r);
}
void update(int i,int &j,int l,int r,int x,int k)
{
	j=++tot;
	tree[j]=tree[i];
	if(l==r)
	{
		tree[j].data=k;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
		update(tree[i].ls,tree[j].ls,l,mid,x,k);
	else
		update(tree[i].rs,tree[j].rs,mid+1,r,x,k);
}
int query(int i,int l,int r,int x)
{
	if(l==r)
		return i;
	int mid=(l+r)>>1;
	if(x<=mid)
		return query(tree[i].ls,l,mid,x);
	else
		return query(tree[i].rs,mid+1,r,x);
}
int find(int ver,int x)
{
	int f=tree[query(rt[ver],1,n,x)].data;
	return f==x ? f : find(ver,f);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(rt[0],1,n);
	for(int i=1;i<=m;i++)
	{
		int op,a,b;
		scanf("%d%d",&op,&a);
		if(op==1)
		{
			scanf("%d",&b);
			int x=query(rt[i-1],1,n,find(i-1,a)),y=query(rt[i-1],1,n,find(i-1,b));
			if(tree[x].siz<tree[y].siz)
			{
				tree[y].siz+=tree[x].siz;
				update(rt[i-1],rt[i],1,n,tree[x].id,tree[y].id);
			}
			else
			{
				tree[x].siz+=tree[y].siz;
				update(rt[i-1],rt[i],1,n,tree[y].id,tree[x].id);
			}
		}
		else if(op==2)
			rt[i]=rt[a];
		else
		{
			scanf("%d",&b);
			rt[i]=rt[i-1];
			int x=query(rt[i],1,n,a),y=query(rt[i],1,n,b);
			printf("%d\n",find(i,tree[x].id)==find(i,tree[y].id));
		}
	}
	return 0;
}