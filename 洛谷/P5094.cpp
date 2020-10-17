#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
#define int long long
using namespace std;
struct Input
{
	int v;
	int x;
};
struct node
{
	int sum;
	int cnt;
};
bool cmp(Input a,Input b)
{
	return a.v<b.v;
}
Input a[50001];
node tree[50001];
int n,maxn,ans;
void update(int x,int sum)
{
	while(x<=maxn)
	{
		tree[x].sum+=sum;
		tree[x].cnt++;
		x+=lowbit(x);
	}
}
node query(int x)
{
	int cnt=0,sum=0;
	while(x)
	{
		sum+=tree[x].sum;
		cnt+=tree[x].cnt;
		x-=lowbit(x);
	}
	return node{sum,cnt};
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].v,&a[i].x);
		maxn=max(maxn,a[i].x);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		node t1=query(a[i].x),t2=query(maxn);
		ans+=(a[i].x*t1.cnt-t1.sum)*a[i].v+((t2.sum-t1.sum)-a[i].x*(t2.cnt-t1.cnt))*a[i].v;
		update(a[i].x,a[i].x);
	}
	printf("%lld",ans);
	return 0;
}
