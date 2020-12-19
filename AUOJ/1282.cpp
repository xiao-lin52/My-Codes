#include<bits/stdc++.h>
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
		register int f=1;
		register char ch=getchar();
		while(!isdigit(ch))
		{
			if(ch==45)
				f=-1;
			ch=getchar();
		}
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
		x*=f;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args)
	{
		read(t);read(args...);
	}
}
using namespace IO;
typedef long long ll;
const int N=1e5+10;
int n,m,vis[N],vis1[N],in[N],in1[N];
ll w[N],ans[2],dp[N][4],dp1[N][4];
vector<int> edge[N],edge1[N];
void dfs(int u)
{
	if(vis[u])
		return;
	vis[u]=1;
	dp[u][0]=w[u];
	dp[u][1]=u;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		dfs(v);
		if(dp[v][0]+w[u]>dp[u][0]||(dp[v][0]+w[u]==dp[u][0]&&dp[u][2]<dp[dp[v][1]][3]))
		{
			dp[u][0]=dp[v][0]+w[u];
			dp[u][1]=dp[v][1];
			dp[u][2]=dp[dp[v][1]][3];
		}
		dp[u][3]=max(dp[u][3],max(dp[v][3],dp[v][0]));
	}
}
void dfs1(int u)
{
	if(vis1[u])
		return;
	vis1[u]=1;
	dp1[u][0]=w[u];
	dp1[u][1]=u;
	for(int i=0;i<edge1[u].size();i++)
	{
		int v=edge1[u][i];
		dfs1(v);
		if(dp1[v][0]+w[u]>dp1[u][0]||(dp1[v][0]+w[u]==dp1[u][0]&&dp1[u][2]<dp1[dp1[v][1]][3]))
		{
			dp1[u][0]=dp1[v][0]+w[u];
			dp1[u][1]=dp1[v][1];
			dp1[u][2]=dp1[dp1[v][1]][3];
		}
		dp1[u][3]=max(dp1[u][3],max(dp1[v][3],dp1[v][0]));
	}
}
signed main()
{
	read(n,m);
	for(int i=1;i<=n;i++)
		read(w[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		read(u,v);
		edge[u].push_back(v);
		edge1[v].push_back(u);
		in[v]++;
		in1[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		sort(edge[i].begin(),edge[i].end());
		edge[i].erase(unique(edge[i].begin(),edge[i].end()),edge[i].end());
		sort(edge1[i].begin(),edge1[i].end());
		edge1[i].erase(unique(edge1[i].begin(),edge1[i].end()),edge1[i].end());
	}
	for(int i=1;i<=n;i++)
		if(!in[i])
			dfs(i);
	for(int i=1;i<=n;i++)
		if(!in1[i])
			dfs1(i);
	for(int i=1;i<=n;i++)
		if(dp[i][0]>ans[0]||(dp[i][0]==ans[0]&&ans[1]<max(dp1[i][3],dp[i][2])))
		{
			ans[0]=dp[i][0];
			ans[1]=max(dp[i][2],dp1[i][3]);
		}
	printf("%lld %lld",ans[0],ans[1]);
	return 0;
}