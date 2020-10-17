#include<cstdio>
#include<cstring>
#define min(a,b) a<b? a:b
#define Inf 0x3f3f3f3f
using namespace std;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[20001];
int n,cnt,head[201],dis[201][201];
void add_edge(int u,int v,int c)
{
	edge[cnt].to=v;
	edge[cnt].w=c;
	edge[cnt].next=head[u];
	head[u]=cnt;
	cnt++;
}
int main()
{
	scanf("%d",&n);
	cnt=1;
	memset(dis,Inf,sizeof(dis));
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int t;
			scanf("%d",&t);
			add_edge(i,j,t);
			dis[i][j]=t;
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=head[k];j!=0;j=edge[j].next)
					dis[i][edge[j].to]=min(dis[i][edge[j].to],dis[i][k]+edge[j].w);
	printf("%d",dis[1][n]);
	return 0;
}
