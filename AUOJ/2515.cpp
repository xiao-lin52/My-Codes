#include<bits/stdc++.h>
#define N 100010
using namespace std;
struct Query
{
	int l;
	int r;
	int id;
	bool operator < (Query const &a) const
	{
		return r<a.r;
	}
};
Query q[N],a[N];
int n,k,m,p,s,cnt,sum,maxn,ans[N],vis[N],mn[N],mx[N];
vector<int> edge[N];
void dfs(int u,int fa)
{
	sum++;
	vis[u]=p;
	mn[p]=min(mn[p],u);
	mx[p]=max(mx[p],u);
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v!=fa)
			cnt++;
		if(!vis[v])
			dfs(v,u);
	}
}
int main()
{
	memset(mn,0x3f,sizeof(mn));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			p++;
			cnt=sum=0;
			dfs(i,0);
			if(cnt==sum-1)
			{
				s++;
				a[s].l=mn[p];
				a[s].r=mx[p];
			}
		}
	sort(q+1,q+1+m);
	sort(a+1,a+1+s);
	int j=1;
	for(int i=1;i<=m;i++)
	{
		while(a[j].r<=q[i].r&&j<=s)
		{
			maxn=max(maxn,a[j].l);
			j++;
		}
		if(q[i].l>maxn)
			ans[q[i].id]=1;
	}
	for(int i=1;i<=m;i++)
		if(ans[i])
			printf("Yes\n");
		else
			printf("No\n");
	return 0;
}
