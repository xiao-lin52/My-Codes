#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct SegTree
{
	int l;
	int r;
	double data;
	double sum;
	double f;
};
SegTree tree[N<<2];
int n,m;
inline void push_up(int i)
{
	tree[i].data=tree[i<<1].data+tree[i<<1|1].data;
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
}
inline void push_down(int i)
{
	if(!tree[i].f)
		return;
	tree[i<<1].sum+=2*tree[i].f*tree[i<<1].data+tree[i].f*tree[i].f*(tree[i<<1].r-tree[i<<1].l+1);
	tree[i<<1].data+=(tree[i<<1].r-tree[i<<1].l+1)*tree[i].f;
	tree[i<<1].f+=tree[i].f;
	tree[i<<1|1].sum+=2*tree[i].f*tree[i<<1|1].data+tree[i].f*tree[i].f*(tree[i<<1|1].r-tree[i<<1|1].l+1);
	tree[i<<1|1].data+=(tree[i<<1|1].r-tree[i<<1|1].l+1)*tree[i].f;
	tree[i<<1|1].f+=tree[i].f;
	tree[i].f=0;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		scanf("%lf",&tree[i].data);
		tree[i].sum=tree[i].data*tree[i].data;
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	push_up(i);
}
void update(int i,int l,int r,double k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].sum+=2*k*tree[i].data+k*k*(tree[i].r-tree[i].l+1);
		tree[i].data+=(tree[i].r-tree[i].l+1)*k;
		tree[i].f+=k;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,k);
	push_up(i);
}
double query_1(int i,int l,int r)
{
	double ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans+=query_1(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		ans+=query_1(i<<1|1,l,r);
	return ans;
}
double query_2(int i,int l,int r)
{
	double ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].sum;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans+=query_2(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		ans+=query_2(i<<1|1,l,r);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		double op,x,y,z;
		scanf("%lf%lf%lf",&op,&x,&y);
		if(op==1)
		{
			scanf("%lf",&z);
			update(1,x,y,z);
		}
		if(op==2)
		{
			printf("%.4lf\n",query_1(1,x,y)/(y-x+1));
		}
		if(op==3)
		{
			double sum=query_1(1,x,y),ave;
			ave=sum/(y-x+1);
			printf("%.4lf\n",(query_2(1,x,y)-2*ave*sum+ave*ave*(y-x+1))/(y-x+1));
		}
	}
	return 0;
}
