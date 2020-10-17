#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
struct node
{
	int x;
	int d;
};
struct cmp
{
	bool operator() (const node a,const node b)
	{
		return a.d>b.d;
	}
};
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[2901];
int n,m,k,cnt,ans=1000000000,a[801],head[801],dis[801],b[801];
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
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		add_edge(u,v,c);
		add_edge(v,u,c);
	}
	for(int c=1;c<=m;c++)
	{
		memset(b,0,sizeof(b));
		memset(dis,0x3f3f3f,sizeof(dis));
		priority_queue<node,vector<node>,cmp> p;
		p.push(node{c,0});
		dis[c]=0;
		while(p.size())
		{
			node u=p.top();
			p.pop();
			if(u.d>dis[u.x])
				continue;
			b[u.x]=1;
			for(int i=head[u.x];i;i=edge[i].next)
			{
				int v=edge[i].to,c=edge[i].w;
				if(!b[v]&&dis[u.x]+c<dis[v])
				{
					dis[v]=dis[u.x]+c;
					p.push(node{v,dis[v]});
				}
			}
		}
		int t=0;
		for(int i=1;i<=n;i++)
			t+=dis[a[i]];
		ans=min(ans,t);
	}
	printf("%d",ans);
	return 0;
}
