#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
struct qwq
{
	ll x;
	ll y;
	ll z;
};
bool cmp(qwq a,qwq b)
{
	if(a.z!=b.z) return a.z<b.z;
	if(a.x!=b.x) return a.x<b.x;
	if(a.y!=b.y) return a.y<b.y;
}
ll dist(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
}
ll t,n,h,r,s,flag;
qwq tree[1010],g[1010];
int main()
{
	scanf("%lld",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%lld%lld%lld",&n,&h,&r);
		s=0;
		flag=0;
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&g[i].x,&g[i].y,&g[i].z);
		sort(g+1,g+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			flag=0;
			if(g[i].z-r<=0)
			{
				s++;
				tree[s].x=g[i].x;
				tree[s].y=g[i].y;
				tree[s].z=g[i].z;
			}
			for(int j=1;j<=s;j++)
				if(dist(g[i].x,g[i].y,g[i].z,tree[j].x,tree[j].y,tree[j].z)<=4*r*r)
				{
					s++;
					tree[s].x=g[i].x;
					tree[s].y=g[i].y;
					tree[s].z=g[i].z;
					break;
				}
			if(tree[s].z+r>=h)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
