#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
using namespace std;
const int inf=0x3f3f3f;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[15001];
int n,m,s,t,u,v,c,cnt,dis[2501],head[2501],b[2501];
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
	scanf("%d%d%d%d",&n,&m,&s,&t);
	memset(head,-1,sizeof(head));
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		add_edge(u,v,c);
		add_edge(v,u,c);
	}
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		int mj=0,minn=inf;
		for(int j=1;j<=n;j++)
			if(b[j]==0&&dis[j]<minn)
			{
				mj=j;
				minn=dis[j];
			}
		if(mj==0)
			break;
		b[mj]=1;
		for(int j=head[mj];j!=-1;j=edge[j].next)
			dis[edge[j].to]=min(dis[edge[j].to],dis[mj]+edge[j].w);
	}
	printf("%d",dis[t]);
	return 0;
}
