#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
struct Edge
{
	ll to;
	ll w;
	ll id;
};
vector<Edge> edge[N];
ll n,m,ans,u[N],v[N],c[N],size[N],cnt[N];
void dfs(ll u,ll fa)
{
	size[u]=1;
	for(int i=0;i<edge[u].size();i++)
	{
		Edge now=edge[u][i];
		if(now.to!=fa)
		{
			dfs(now.to,u);
			cnt[now.id]=size[now.to]*(n-size[now.to]);
			size[u]+=size[now.to];
		}
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n-1;i++)
	{
		Edge t1,t2;
		u[i]=read(),v[i]=read(),c[i]=read();
		t1.to=v[i];
		t1.w=c[i];
		t1.id=i;
		t2.to=u[i];
		t2.w=c[i];
		t2.id=i;
		edge[u[i]].push_back(t1);
		edge[v[i]].push_back(t2);
	}
	dfs(1,0);
	for(int i=1;i<=n-1;i++)
		ans+=cnt[i]*c[i];
	for(int i=1;i<=m;i++)
	{
		ll k=read(),val=read();
		ans=ans-cnt[k]*(c[k]-val);
		c[k]=val;
		printf("%lld\n",ans);
	}
	return 0;
}
