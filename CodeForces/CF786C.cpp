#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int n,len,num,sum,a[N],belong[N],l[1010],r[1010];
bitset<N> rec,g[1010];
int query(int k)
{
	int ans=0,p;
	bitset<N> cnt;
	for(int i=1;i<=num;i++)
	{
		p=cnt.count();
		bitset<N> tmp=cnt|g[i];
		if(tmp.count()<=k)
			cnt|=g[i];
		else
		{
			int j=l[i];
			while(j<=r[i])
			{
				p=cnt.count();
				while(cnt.count()+(~cnt[a[j]])<=k&&j<=r[i])
					cnt.set(a[j++]);
				if(!(cnt.count()+(~cnt[a[j]])<=k&&j>r[i]))
				{
					ans++;
					cnt.reset();
				}
			}
		}
	}
	if(cnt.count())
		ans++;
	return ans;
}
int main()
{
	scanf("%d",&n);
	len=sqrt(n);
	num=(n-1)/len+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		belong[i]=(i-1)/len+1;
		g[belong[i]].set(a[i]);
	}
	for(int i=1;i<=num;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=min(i*len,n);
		rec|=g[i];
	}
	sum=rec.count();
	for(int i=1;i<sum;i++)
		printf("%d ",query(i));
	for(int i=sum;i<=n;i++)
		printf("1 ");
	return 0;
}
