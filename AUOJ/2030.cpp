#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define inf 0x3f3f3f3f
#define MAXN 100005
using namespace std;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[2*MAXN];
priority_queue< pii,vector<pii>,greater<pii> > q;
int n,m,s,l,ans,cnt,head[MAXN],dis[MAXN],b[MAXN],u[MAXN],v[MAXN],c[MAXN];
void add_edge(int u,int v,int c)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].w=c;
	head[u]=cnt;
}
int main()
{
//	freopen("./missile/missile.in","r",stdin);
	memset(dis,inf,sizeof(dis));
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
		add_edge(u[i],v[i],c[i]);
		add_edge(v[i],u[i],c[i]);
	}
	scanf("%d",&l);
	dis[s]=0;
	q.push(mp(0,s));
	while(q.size())
	{
		int u=q.top().second;
		q.pop();
		if(b[u])
			continue;
		b[u]=1;
		for(int i=head[u]; i; i=edge[i].next)
		{
			int v=edge[i].to,c=edge[i].w;
			if(dis[v]>dis[u]+c&&!b[v])
			{
				dis[v]=dis[u]+c;
				q.push(mp(dis[v],v));
			}
		}
	}
	for(int i=1; i<=n; i++)
		if(dis[i]==l)
			ans++;
	for(int i=1;i<=m;i++)
	{
		if(l-dis[u[i]]+l-dis[v[i]]==c[i]&&dis[u[i]]<l&&dis[v[i]]<l)
			ans++;
		if(l-dis[u[i]]+l-dis[v[i]]<c[i]&&l>dis[u[i]]&&l<dis[u[i]]+c[i])
			ans++;
		if(l-dis[u[i]]+l-dis[v[i]]<c[i]&&l>dis[v[i]]&&l<dis[v[i]]+c[i])
			ans++;
	}
	printf("%d",ans);
//	fclose(stdin);
	return 0;
}

