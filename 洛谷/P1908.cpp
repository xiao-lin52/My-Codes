#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
struct node
{
	int w;
	int id;
};
bool cmp(node a,node b)
{
	return a.w<b.w;
}
node t[500001];
int n,a[500001];
long long k,res,tree[500001];
void update(int x,int k)
{
	while(x<=n)
	{
		tree[x]+=k;
		x+=lowbit(x);
	}
}
long long query(int x)
{
	long long ans=0;
	while(x)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		t[i].w=a[i];
		t[i].id=i;
	}
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(t[i].w!=t[i-1].w)
			k++;
		a[t[i].id]=k;
	}
	for(int i=1;i<=n;i++)
	{
		update(a[i],1);
		res+=query(k)-query(a[i]);
	}
	printf("%lld",res);
	return 0;
}