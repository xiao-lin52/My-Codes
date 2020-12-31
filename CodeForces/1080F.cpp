#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10, inf = 0x3f3f3f3f;
struct Segment
{
	int l;
	int r;
	int p;
	bool operator < (Segment const & x) const
	{
		return r == x.r ? (l == x.l ? p < x.p : l < x.l) : r < x.r;
	}
};
struct SegTree
{
	int ls;
	int rs;
	int dat;
};
SegTree tree[N*30];
Segment q[N];
int n, m, k, tot, c[N], rt[N];
inline void push_up(int i)
{
	if(tree[i].ls && tree[i].rs)
		tree[i].dat = min(tree[tree[i].ls].dat, tree[tree[i].rs].dat);
	else
		tree[i].dat = 0;
}
void update(int &i, int p, int l, int r, int x, int k)
{
	i = ++tot;
	tree[i] = tree[p];
	if(l == r)
	{
		tree[i].dat = max(tree[i].dat, k);
		return;
	}
	int mid = (l+r)>>1;
	if(x <= mid)
		update(tree[i].ls, tree[p].ls, l, mid, x, k);
	else
		update(tree[i].rs, tree[p].rs, mid+1, r, x, k);
	push_up(i);
}
int query(int i, int l, int r, int x, int y)
{
	if(!i)
		return 0;
	if(x <= l && y >= r)
		return tree[i].dat;
	int mid = (l+r)>>1, ans = inf;
	if(x <= mid)
		ans = min(ans, query(tree[i].ls, l, mid, x, y));
	if(mid+1 <= y)
		ans = min(ans, query(tree[i].rs, mid+1, r, x, y));
	return ans;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].p);
		c[i] = q[i].r;
	}
	sort(c+1, c+1+k);
	sort(q+1, q+1+k);
	for(int i = 1; i <= k; i++)
		update(rt[i], rt[i-1], 1, n, q[i].p, q[i].l);
	while(m--)
	{
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		y = upper_bound(c+1, c+1+k, y)-c-1;
		if(y == 0)
			printf("no\n");
		else
			if(query(rt[y], 1, n, a, b) < x)
				printf("no\n");
			else
				printf("yes\n");
		fflush(stdout);
	}
	return 0;
}