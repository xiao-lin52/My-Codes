#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
#define N 100010
using namespace std;
ll t,n,v,num,ans,a[N],rec[N];
queue<int> q;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		num=1;
		memset(rec,0,sizeof(rec));
		while(q.size())
			q.pop();
		scanf("%lld%lld",&n,&v);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		if(!v)
		{
			printf("%lld\n",n*(n+1)/2);
			continue;
		}
		for(int i=n;i>=1;i--)
			rec[i]=a[i] ? rec[i+1]+1 : 0;
		for(int r=1;r<=n;r++)
		{
			if(!a[r])
			{
				while(q.size())
					q.pop();
				num=1;
				continue;
			}
			q.push(a[r]);
			num*=a[r];
			while(q.size()&&num>=v)
			{
				num/=q.front();
				q.pop();
				ans+=rec[r];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
