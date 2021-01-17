#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r); i <= i##end; i++)
#define per(i, r, l) for(int i = (r), i##end = (l); i >= i##end; i--)
#define debug(x) cerr<<#x<<" = "<<x
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define judge(p) (tree[p].r-tree[p].l+1 == tree[p].lz)
using namespace std;
typedef long long ll;
const int N = 5e4+10, inf = 0x3f3f3f3f;
struct SegTree
{
	int l;
	int r;
	int data;
	int tag;
	int lz;
	int rz;
};
SegTree tree[N<<2];
int n, m;
inline void push_up(int p)
{
	if(judge(p<<1))
		tree[p].lz = tree[p<<1].lz+tree[p<<1|1].lz;
	else
		tree[p].lz = tree[p<<1].lz;
	if(judge(p<<1|1))
		tree[p].rz = tree[p<<1|1].rz+tree[p<<1].rz;
	else
		tree[p].rz = tree[p<<1|1].rz;
	tree[p].data = max(tree[p<<1].rz+tree[p<<1|1].lz, max(tree[p<<1].data, tree[p<<1|1].data));
}
inline void push_down(int p)
{
	if(tree[p].tag == 0)
		return;
	if(tree[p].tag == 1)
	{
		tree[p<<1].lz = tree[p<<1].rz = tree[p<<1].data = tree[p<<1|1].lz = tree[p<<1|1].rz = tree[p<<1|1].data = 0;
		tree[p<<1].tag = tree[p<<1|1].tag = 1;
	}
	if(tree[p].tag == 2)
	{
		tree[p<<1].lz = tree[p<<1].rz = tree[p<<1].r-tree[p<<1].l+1;
		tree[p<<1|1].lz = tree[p<<1|1].rz = tree[p<<1|1].r-tree[p<<1|1].l+1;
		tree[p<<1].data = tree[p<<1|1].data = 0;
		tree[p<<1].tag = tree[p<<1|1].tag = 2;
	}
	tree[p].tag = 0;
}
void build(int p, int l, int r)
{
	tree[p].l = l;
	tree[p].r = r;
	if(l == r)
	{
		tree[p].lz = tree[p].rz = 1;
		return;
	}
	int mid = (l+r)>>1;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
	push_up(p);
}
void update(int p, int x, int y, int k)
{
	if(tree[p].l >= x && tree[p].r <= y)
	{
		if(k)
		{
			tree[p].lz = tree[p].rz = tree[p].data = 0;
			tree[p].tag = 1;
		}
		else
		{
			tree[p].lz = tree[p].rz = tree[p].r-tree[p].l+1;
			tree[p].data = 0;
			tree[p].tag = 2;
		}
		return;
	}
	push_down(p);
	if(tree[p<<1].r >= x)
		update(p<<1, x, y, k);
	if(tree[p<<1|1].l <= y)
		update(p<<1|1, x, y, k);
	push_up(p);
}
int query(int p, int k, int flag)
{
	if(tree[p].lz < k && tree[p].data < k && tree[p].rz < k)
		return 0;
	if(tree[p].l == tree[p].r)
		return tree[p].l;
	push_down(p);
	if(flag)
	{
		if(k > tree[p<<1|1].rz)
			return query(p<<1, tree[p<<1].rz, flag);
		else
			return query(p<<1|1, k, flag);
	}
	if(tree[p<<1].data >= k || tree[p<<1].lz >= k || tree[p<<1].rz >= k)
		return query(p<<1, k, 0);
	if(tree[p<<1].rz+tree[p<<1|1].lz >= k && tree[p<<1].rz)
		return query(p<<1, tree[p<<1].rz, 1);
	if(tree[p<<1|1].data >= k || tree[p<<1|1].lz >= k || tree[p<<1|1].rz >= k)
		return query(p<<1|1, k, 0);
	return 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	rep(i, 1, m)
	{
		int op, l, r, k;
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%d", &k);
			int t = query(1, k, 0);
			printf("%d\n", t);
			if(t)
				update(1, t, t+k-1, 1);
		}
		else
		{
			scanf("%d%d", &l, &r);
			update(1, l, l+r-1, 0);
		}
	}
	return 0;
}