#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
using namespace std;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[10001];
int n,s,t,cnt,head[101],b[101],dis[101];
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
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&s,&t);
	for(int i=1;i<=n;i++)
	{
		dis[i]=1000000000;
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int t;
			scanf("%d",&t);
			add_edge(i,t,j==1? 0:1);
		}
	}
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		int mj=0,minn=0x3f3f3f;
		for(int j=1;j<=n;j++)
			if(b[j]==0&&minn>dis[j])
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
	if(dis[t]!=1000000000)
		printf("%d",dis[t]);
	else
		printf("-1");
	return 0;
}
