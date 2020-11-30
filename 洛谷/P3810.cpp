#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e5+10;
struct CDQ
{
	int x,y,z,s,f;
	bool operator < (CDQ b)
	{
		return x==b.x ? (y==b.y ? z<b.z : y<b.y) : x<b.x;
	}
};
bool cmp2(CDQ a,CDQ b)
{
	return a.y==b.y ? a.z<b.z : a.y<b.y;
}
CDQ a[N],tmp[N];
int n,k,rec[N],b[N],tree[N<<1];
void update(int x,int y)
{
	for(;x<=k;x+=lowbit(x))
		tree[x]+=y;
}
int query(int x)
{
	int sum=0;
	for(;x>=1;x-=lowbit(x))
		sum+=tree[x];
	return sum;
}
void solve(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1,i=l,j=mid+1,qwq=l-1,qaq=0;
	solve(l,mid);
	solve(mid+1,r);
	while(i<=mid&&j<=r)
		if(a[i].y<=a[j].y)
		{
			tmp[++qwq]=a[i];
			rec[++qaq]=i;
			update(a[i].z,a[i].s);
			i++;
		}
		else
		{
			a[j].f+=query(a[j].z);
			tmp[++qwq]=a[j];
			j++;
		}
	while(i<=mid)
	{
		tmp[++qwq]=a[i];
		i++;
	}
	while(j<=r)
	{
		a[j].f+=query(a[j].z);
		tmp[++qwq]=a[j];
		j++;
	}
	rep(p,1,qaq)
		update(a[rec[p]].z,-a[rec[p]].s);
	rep(p,l,r)
		a[p]=tmp[p];
}
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,1,n)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+1+n);
	int lst=1;
	a[1].s++;
	for(int i=2;i<=n;i++)
	{
		if(a[i].x==a[i-1].x&&a[i].y==a[i-1].y&&a[i].z==a[i-1].z)
			a[lst].s++;
		else
		{
			lst=i;
			a[i].s++;
		}
	}
	solve(1,n);
	rep(i,1,n)
		b[a[i].f+a[i].s-1]+=a[i].s;
	rep(i,0,n-1)
		printf("%d\n",b[i]);
	return 0;
}