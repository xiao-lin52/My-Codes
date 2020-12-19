#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N],fa[N];
ll cnt,s[N];
vector<int> edge[N];
void dfs(int u,int f)
{
	fa[u]=f;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=f)
		{
			dfs(v,u);
			s[u]+=s[v];
		}
	}
	s[u]+=a[u];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=fa[i];j;j=fa[j])
			if(s[j]-s[i]-a[j]>a[i])
				break;
			else
				if((a[i]^a[j])==s[j]-s[i])
					cnt++;
	}
	printf("%lld",cnt);
	return 0;
}