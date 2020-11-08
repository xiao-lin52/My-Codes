#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,k,tree[N];
char a[N],ans[N];
deque<int> pos[30];
void update(int x,int k)
{
	for(;x<=n;x+=lowbit(x))
		tree[x]+=k;
}
ll query(int x)
{
	ll sum=0;
	for(;x>=1;x-=lowbit(x))
		sum+=tree[x];
	return sum;
}
int main()
{
	scanf("%lld%lld%s",&n,&k,a+1);
	for(int i=1;i<=n;i++)
	{
		pos[a[i]-'a'+1].push_back(i);
		update(i,1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=26;j++)
		{
			if(pos[j].size())
			{
				int t=query(pos[j].front());
				if(t-1<=k)
				{
					ans[i]=j+'a'-1;
					update(pos[j].front(),-1);
					pos[j].pop_front();
					k-=t-1;
					break;
				}
			}
		}
	}
	printf("%s",ans+1);
	return 0;
}
