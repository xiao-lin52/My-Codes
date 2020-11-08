#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,ans,fa[N],dp[N],rec[N];
char a[N];
vector<ll> edge[N];
stack<int> st;
void dfs(ll u)
{
	if(a[u]=='(')
	{
		st.push(u);
		for(int i=0;i<edge[u].size();i++)
			dfs(edge[u][i]);
		st.pop();
	}
	else
		if(st.size())
		{
			int t=st.top();
			st.pop();
			dp[u]=dp[fa[t]]+1;
			for(int i=0;i<edge[u].size();i++)
				dfs(edge[u][i]);
			st.push(t);
		}
		else
			for(int i=0;i<edge[u].size();i++)
				dfs(edge[u][i]);
}
void dfs2(int u)
{
	dp[u]+=dp[fa[u]];
	ans^=dp[u]*u;
	for(int i=0;i<edge[u].size();i++)
		dfs2(edge[u][i]);
}
int main()
{
	scanf("%lld%s",&n,a+1);
	for(ll i=2;i<=n;i++)
	{
		scanf("%lld",&fa[i]);
		edge[fa[i]].push_back(i);
	}
	dfs(1);
	dfs2(1);
	printf("%lld",ans);
	return 0;
}