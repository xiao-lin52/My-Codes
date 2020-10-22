#include<bits/stdc++.h>
#define N 5010
#define lowbit(x) x&(-x)
using namespace std;
struct Unknown
{
	int data;
	int id;
};
bool cmp1(Unknown a,Unknown b)
{
	return a.data<b.data;
}
bool cmp2(Unknown a,Unknown b)
{
	return a.id<b.id;
}
Unknown b[N];
int n,m,ans,num[N],c[N],tree[N];
void update(int x)
{
	for(;x<=n;x+=lowbit(x))
		tree[x]++;
}
int query(int x)
{
	int sum=0;
	for(;x>=1;x-=lowbit(x))
		sum+=tree[x];
	return sum;
}
int main()
{
	while(~scanf("%d",&n))
	{
		ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i].data);
			b[i].id=i;
		}
		sort(b+1,b+1+n,cmp1);
		b[0].data=b[1].data-1;
		for(int i=1;i<=n;i++)
		{
			if(b[i].data!=b[i-1].data)
				b[i].data=++m;
		}
		sort(b+1,b+1+n,cmp2);
		for(int i=1;i<=n;i++)
		{
			num[i]=query(n)-query(b[i].data);
			update(b[i].data);
		}
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,num[n]+(i-1)*(n-i+1))
		}
	}
	return 0;
}