#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct SegTree
{
	int l,r,data,mx1,l1,r1,mx0,l0,r0,f[3];
};
struct Seg
{
	int lc,rc,mc;
};
SegTree tree[N<<2];
int n,m;
inline void push_up(int i)
{
	tree[i].data=tree[i<<1].data+tree[i<<1|1].data;
	tree[i].mx0=max(tree[i<<1].r0+tree[i<<1|1].l0,max(tree[i<<1].mx0,tree[i<<1|1].mx0));
	tree[i].mx1=max(tree[i<<1].r1+tree[i<<1|1].l1,max(tree[i<<1].mx1,tree[i<<1|1].mx1));
	tree[i].l0=tree[i<<1].l0;
	tree[i].r0=tree[i<<1|1].r0;
	tree[i].l1=tree[i<<1].l1;
	tree[i].r1=tree[i<<1|1].r1;
	if(tree[i<<1].l1==tree[i<<1].r-tree[i<<1].l+1)
		tree[i].l1+=tree[i<<1|1].l1;
	if(tree[i<<1|1].r1==tree[i<<1|1].r-tree[i<<1|1].l+1)
		tree[i].r1+=tree[i<<1].r1;
	if(tree[i<<1].l0==tree[i<<1].r-tree[i<<1].l+1)
		tree[i].l0+=tree[i<<1|1].l0;
	if(tree[i<<1|1].r0==tree[i<<1|1].r-tree[i<<1|1].l+1)
		tree[i].r0+=tree[i<<1].r0;
}
inline void push_down(int i)
{
	if(tree[i].f[0])
	{
		tree[i<<1].data=tree[i<<1].mx1=tree[i<<1].l1=tree[i<<1].r1=0;
		tree[i<<1|1].data=tree[i<<1|1].mx1=tree[i<<1|1].l1=tree[i<<1|1].r1=0;
		tree[i<<1].mx0=tree[i<<1].l0=tree[i<<1].r0=tree[i<<1].r-tree[i<<1].l+1;
		tree[i<<1|1].mx0=tree[i<<1|1].l0=tree[i<<1|1].r0=tree[i<<1|1].r-tree[i<<1|1].l+1;
		tree[i<<1].f[0]=tree[i<<1|1].f[0]=1;
		tree[i<<1].f[1]=tree[i<<1].f[2]=tree[i<<1|1].f[1]=tree[i<<1|1].f[2]=0;
	}
	if(tree[i].f[1])
	{
		tree[i<<1].data=tree[i<<1].mx1=tree[i<<1].l1=tree[i<<1].r1=tree[i<<1].r-tree[i<<1].l+1;
		tree[i<<1|1].data=tree[i<<1|1].mx1=tree[i<<1|1].l1=tree[i<<1|1].r1=tree[i<<1|1].r-tree[i<<1|1].l+1;
		tree[i<<1].mx0=tree[i<<1].l0=tree[i<<1].r0=0;
		tree[i<<1|1].mx0=tree[i<<1|1].l0=tree[i<<1|1].r0=0;
		tree[i<<1].f[1]=tree[i<<1|1].f[1]=1;
		tree[i<<1].f[0]=tree[i<<1].f[2]=tree[i<<1|1].f[0]=tree[i<<1|1].f[2]=0;
	}
	if(tree[i].f[2])
	{
		tree[i<<1].data=tree[i<<1].r-tree[i<<1].l+1-tree[i<<1].data;
		tree[i<<1|1].data=tree[i<<1|1].r-tree[i<<1|1].l+1-tree[i<<1|1].data;
		swap(tree[i<<1].l1,tree[i<<1].l0);
		swap(tree[i<<1].r1,tree[i<<1].r0);
		swap(tree[i<<1].mx1,tree[i<<1].mx0);
		swap(tree[i<<1|1].l1,tree[i<<1|1].l0);
		swap(tree[i<<1|1].r1,tree[i<<1|1].r0);
		swap(tree[i<<1|1].mx1,tree[i<<1|1].mx0);
		if(tree[i<<1].f[0]||tree[i<<1].f[1])
		{
			tree[i<<1].f[0]^=1;
			tree[i<<1].f[1]^=1;
		}
		else
			tree[i<<1].f[2]^=1;
		if(tree[i<<1|1].f[0]||tree[i<<1|1].f[1])
		{
			tree[i<<1|1].f[0]^=1;
			tree[i<<1|1].f[1]^=1;
		}
		else
			tree[i<<1|1].f[2]^=1;
	}
	tree[i].f[0]=tree[i].f[1]=tree[i].f[2]=0;
}
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		scanf("%d",&tree[i].data);
		tree[i].mx1=tree[i].l1=tree[i].r1=tree[i].data;
		tree[i].mx0=tree[i].l0=tree[i].r0=tree[i].data^1;
		return;
	}
	build(i<<1,l,(l+r)>>1);
	build(i<<1|1,((l+r)>>1)+1,r);
	push_up(i);
}
void update(int i,int l,int r,int p)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		if(p==2)
		{
			if(tree[i].f[0])
			{
				p=1;
				goto l;
			}
			if(tree[i].f[1])
			{
				p=0;
				goto l;
			}
			tree[i].data=tree[i].r-tree[i].l+1-tree[i].data;
			swap(tree[i].l1,tree[i].l0);
			swap(tree[i].r1,tree[i].r0);
			swap(tree[i].mx1,tree[i].mx0);
			tree[i].f[2]^=1;
		}
		l:;
		if(p==0)
		{
			tree[i].data=tree[i].mx1=tree[i].l1=tree[i].r1=0;
			tree[i].mx0=tree[i].l0=tree[i].r0=tree[i].r-tree[i].l+1;
			tree[i].f[1]=tree[i].f[2]=0;
			tree[i].f[0]=1;
		}
		if(p==1)
		{
			tree[i].data=tree[i].mx1=tree[i].l1=tree[i].r1=tree[i].r-tree[i].l+1;
			tree[i].mx0=tree[i].l0=tree[i].r0=0;
			tree[i].f[0]=tree[i].f[2]=0;
			tree[i].f[1]=1;
		}
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l)
		update(i<<1,l,r,p);
	if(tree[i<<1|1].l<=r)
		update(i<<1|1,l,r,p);
	push_up(i);
}
int query_0(int i,int l,int r)
{
	int ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i<<1].r>=l)
		ans+=query_0(i<<1,l,r);
	if(tree[i<<1|1].l<=r)
		ans+=query_0(i<<1|1,l,r);
	return ans;
}
Seg query_1(int i,int l,int r)
{
	int ans=0,flag=0,tl=0,tr=0;
	Seg tmp1={0,0,0},tmp2={0,0,0};
	if(tree[i].l>=l&&tree[i].r<=r)
		return (Seg){tree[i].l1,tree[i].r1,tree[i].mx1};
	push_down(i);
	if(tree[i<<1].r>=l)
	{
		tmp1=query_1(i<<1,l,r);
		ans=max(ans,tmp1.mc);
		tl=tmp1.lc;
		flag++;
	}
	if(tree[i<<1|1].l<=r)
	{
		tmp2=query_1(i<<1|1,l,r);
		ans=max(ans,tmp2.mc);
		tr=tmp2.rc;
		flag++;
	}
	if(tmp1.lc==tree[i<<1].r-tree[i].l+1)
		tl+=tmp2.lc;
	if(tmp2.rc==tree[i<<1|1].r-tree[i<<1|1].l+1)
		tr+=tmp1.rc;
	ans=max(ans,tmp1.rc+tmp2.lc);
	return (Seg){tl,tr,ans};
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==0||op==1||op==2)
			update(1,x+1,y+1,op);
		if(op==3)
			printf("%d\n",query_0(1,x+1,y+1));
		if(op==4)
			printf("%d\n",query_1(1,x+1,y+1).mc);
	}
	return 0;
}