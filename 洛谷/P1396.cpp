#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge[40001];
vector<int>head(10001,-1);
vector<int>b(10001,0);
vector<int>dis(10001,100000000);
int n,m,s,t,cnt;
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
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a,b,c);
		add_edge(b,a,c);
	}
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		int mj=0,minn=100000000;
		for(int j=1;j<=n;j++)
			if(b[j]==0&&minn>dis[j])
			{
				mj=j;
				minn=dis[j];
			}
		if(mj==0)
			break;
		b[mj]=1;
		for(int j=head[mj];j!=-1;j=edge[j].next)
			dis[edge[j].to]=min(dis[edge[j].to],max(dis[mj],edge[j].w));
	}
	printf("%d",dis[t]);
	return 0;
}
