#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	int r;
	bitset<2001> data;
	int f;
};
node tree[400001];
int n,m,k,cnt,x[1001],y[1001],p[2001];
map<int,int> b;
void push_down(int i)
{
	int l=i<<1,r=i<<1|1;
	if(!tree[i].f)
		return;
	tree[l].f=1;
	tree[r].f=1;
	tree[l].data=tree[i].data;
	tree[r].data=tree[i].data;
	tree[i].f=0;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
		return;
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
}
void update(int i,int l,int r,int k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data.reset();
		tree[i].data[k]=1;
		tree[i].f=1;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k);
	tree[i].data=tree[i<<1].data|tree[i<<1|1].data;
}
bitset<2001> query(int i,int l,int r)
{
	bitset<2001> ans;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans|=query(i<<1,l,(l+r)>>1);
	if(tree[i<<1|1].l<=r)
		ans|=query(i<<1|1,((l+r)>>1)+1,r);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		p[++k]=x[i];
		p[++k]=y[i];
	}
	p[0]=p[1];
	sort(p+1,p+1+k);
	for(int i=k;i>=1;i--)
		if(p[i]!=p[i-1])
			p[++k]=p[i-1]+1;
	sort(p+1,p+1+k);
	k=unique(p+1,p+1+k)-(p+1);
	for(int i=1;i<=k;i++)
		b[p[i]]=++cnt;
	build(1,1,cnt);
	for(int i=1;i<=m;i++)
		update(1,b[x[i]],b[y[i]],i);
	printf("%d",tree[1].data.count());
	return 0;
}