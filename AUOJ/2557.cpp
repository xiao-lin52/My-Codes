#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct QAQ
{
	int x;
	int y;
	int id;
	bool operator < (QAQ const &a) const
	{
		return x<a.x;
	}
};
QAQ q[N];
int t,n,m,l,r,a[N];
bitset<N> num;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		num.set();
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&q[i].x,&q[i].y);
		sort(q+1,q+1+m);
		l=1;
		r=0;
		for(int i=1;i<=m;i++)
		{
			if(q[i].y<r)
				continue;
			while(l<q[i].x)
				num[a[l++]]=1;
			if(l>r)
				r=l-1;
			while(r<q[i].y)
			{
				r++;
				num[0]=0;
				if(!a[r])
					a[r]=num._Find_first();
				num[a[r]]=0;
			}
		}
		for(int i=1;i<=n-1;i++)
			if(a[i])
				printf("%d ",a[i]);
			else
				printf("1 ");
		if(a[n])
			printf("%d",a[n]);
		else
			printf("1");
		printf("\n");
	}
	return 0;
}