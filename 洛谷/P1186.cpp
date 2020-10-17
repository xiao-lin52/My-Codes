#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[1000001];
int n,m,cnt,ans,head[1001],dis[1001],b[1001],pre[1001];
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
	memset(dis,inf,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int minn=inf,u=0;
		for(int j=1;j<=n;j++)
			if(dis[j]<minn&&!b[j])
			{
				minn=dis[j];
				u=j;
			}
		b[u]=1;
		for(int j=head[u];j;j=edge[j].next)
			if(dis[edge[j].to]>dis[u]+edge[j].w)
			{
				dis[edge[j].to]=dis[u]+edge[j].w;
				pre[edge[j].to]=u;
			}
	}
	ans=dis[n];
	for(int p=n;p!=1;p=pre[p])
	{
		memset(dis,inf,sizeof(dis));
		memset(b,0,sizeof(b));
		dis[1]=0;
		for(int i=1;i<=n;i++)
		{
			int minn=inf,u=0;
			for(int j=1;j<=n;j++)
				if(dis[j]<minn&&!b[j])
				{
					minn=dis[j];
					u=j;
				}
			b[u]=1;
			for(int j=head[u];j;j=edge[j].next)
				if((u!=p&&u!=pre[p])||(edge[j].to!=p&&edge[j].to!=pre[p]))
					dis[edge[j].to]=min(dis[edge[j].to],dis[u]+edge[j].w);
		}
		ans=max(ans,dis[n]);
	}
	printf("%d",ans);
	return 0;
}

