#include<cstdio>
#define ll long long
using namespace std;
struct node
{
	ll data;
	int l;
	int r;
	ll f;
};
node tree[800001];
int n,m;
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		scanf("%lld",&tree[i].data);
		return;
	}
	build(i*2,l,(l+r)/2);
	build(i*2+1,(l+r)/2+1,r);
	tree[i].data=tree[i*2].data+tree[i*2+1].data;
}
void push_down(int i)
{
	tree[i*2].data+=tree[i].f*(tree[i*2].r-tree[i*2].l+1);
	tree[i*2+1].data+=tree[i].f*(tree[i*2+1].r-tree[i*2+1].l+1);
	tree[i*2].f+=tree[i].f;
	tree[i*2+1].f+=tree[i].f;
	tree[i].f=0;
}
void update(int i,int l,int r,ll k)
{
	if(tree[i].l>=l&&tree[i].r<=r)
	{
		tree[i].data+=k*(tree[i].r-tree[i].l+1);
		tree[i].f+=k;
		return;
	}
	push_down(i);
	if(tree[i*2].r>=l)
		update(i*2,l,r,k);
	if(tree[i*2+1].l<=r)
		update(i*2+1,l,r,k);
	tree[i].data=tree[i*2].data+tree[i*2+1].data;
}
ll query(int i,int l,int r)
{
	ll ans=0;
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].data;
	push_down(i);
	if(tree[i*2].r>=l)
		ans+=query(i*2,l,r);
	if(tree[i*2+1].l<=r)
		ans+=query(i*2+1,l,r);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,l,r;
		ll k;
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				scanf("%d%d%lld",&l,&r,&k);
				update(1,l,r,k);
				break;
			case 2:
				scanf("%lld",&k);
				update(1,1,1,k);
				break;
			case 3:
				scanf("%lld",&k);
				update(1,1,1,-k);
				break;
			case 4:
				scanf("%d%d",&l,&r);
				printf("%lld\n",query(1,l,r));
				break;
			case 5:
				printf("%lld\n",query(1,1,1));
				break;
		}
	}
	return 0;
}