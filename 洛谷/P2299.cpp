#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f
#define min(a,b) a<b?a:b
using namespace std;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[400001];
int n,m,cnt,head[2501],b[2501],dis[2501];
void add_edge(int u,int v,int c)
{
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].w=c;
	head[u]=cnt;
	cnt++;
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a,b,c);
		add_edge(b,a,c);
	}
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int mj=0,minn=inf;
		for(int j=1;j<=n;j++)
			if(b[j]==0&&dis[j]<minn)
			{
				minn=dis[j];
				mj=j;
			}
		if(mj==0)
			break;
		b[mj]=1;
		for(int j=head[mj];j!=-1;j=edge[j].next)
			dis[edge[j].to]=min(dis[edge[j].to],dis[mj]+edge[j].w);
	}
	printf("%d",dis[n]);
	return 0;
}