#include<bits/stdc++.h>
#define ll int
#define N 100010
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
int t,n,ans,mx[N],a[N],dp[N];
vector<int> sig[N];
void pre()
{
	for(int i=2;i<=sqrt(N);i++)
		for(int j=1;i*j<=N;j++)
			sig[i*j].push_back(i);
}
int main()
{
	t=read();
	pre();
	while(t--)
	{
		ans=0;
		n=read();
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			a[i]=read();
		sort(a+1,a+1+n);
		for(int i=1;i<=a[n];i++)
			mx[i]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<sig[a[i]].size();j++)
				dp[i]=max(dp[i],mx[sig[a[i]][j]]);
			for(int j=0;j<sig[a[i]].size();j++)
				mx[sig[a[i]][j]]=max(mx[sig[a[i]][j]],dp[i]+1);
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
