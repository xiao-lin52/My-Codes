#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
namespace IO
{
	char buf[1<<23],*p1=buf,*p2=buf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	#define isdigit(c) (c>=48&&c<=57)
	#define isalpha(c) (c>=65&&c<=90)
	template<typename T> inline void read(T &x)
	{
		x=0;
		register char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
const int N=1e5+10;
int t,n,k,ans,flag,siz[N],dp[N];
vector<int> edge[N];
void dfs(int u,int fa)
{
	siz[u]=1;
	int sum=0,mx=0;
	rep(i,0,edge[u].size()-1)
	{
		int v=edge[u][i];
		if(v!=fa)
		{
			dfs(v,u);
			siz[u]+=siz[v];
			sum+=(siz[v]>=k);
		}
	}
	mx=sum;
	rep(i,0,edge[u].size()-1)
	{
		int v=edge[u][i];
		if(v!=fa)
		{
			ans=max(ans,mx+dp[v]-(siz[v]>=k)+(n-siz[u]>=k));
			mx=max(mx,sum+dp[v]-(siz[v]>=k));
		}
	}
	dp[u]=max(mx,sum);
}
int main()
{
	read(t);
	while(t--)
	{
		read(n,k);
		ans=0;
		for(int i=1;i<=n;i++)
			edge[i].clear();
		rep(i,1,n-1)
		{
			int u,v;
			read(u,v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}