#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
#define min(a,b) a<b?a:b
using namespace std;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[4000001];
int n,m,cnt,head[2001],dis[2001],b[2001],f[2001];
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
	}
	dis[1]=0;
	f[1]=1;
	for(int i=1;i<=n;i++)
	{
		int minn=inf,u=0,v[2001]={0};
		for(int j=1;j<=n;j++)
			if(dis[j]<minn&&!b[j])
			{
				minn=dis[j];
				u=j;
			}
		b[u]=1;
		for(int j=head[u];j;j=edge[j].next)
		{
			if(dis[edge[j].to]==dis[u]+edge[j].w&&!v[edge[j].to])
				f[edge[j].to]+=f[u];
			if(dis[edge[j].to]>dis[u]+edge[j].w)
			{
				dis[edge[j].to]=dis[u]+edge[j].w;
				f[edge[j].to]=f[u];
			}
			v[edge[j].to]=1;
		}
	}
	if(dis[n]==inf)
		printf("No answer");
	else
		printf("%d %d",dis[n],f[n]);
	return 0;
}
