#include<cstdio>
#define min(a,b) a<b?a:b
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[10001];
int n,cnt,x,y,s,t,head[101];
int tot,ans=101,dfn[101],low[101];
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
void tarjan(int u)
{
	tot++;
	dfn[u]=low[u]=tot;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&dfn[t]>=dfn[v]&&u!=s)
				ans=min(ans,u);
		}
		else
			low[u]=min(low[u],dfn[v]);
	}
}
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	while(x||y)
	{
		add_edge(x,y);
		add_edge(y,x);
		scanf("%d%d",&x,&y);
	}
	scanf("%d%d",&s,&t);
	tarjan(s);
	if(ans==101)
		printf("No solution");
	else
		printf("%d",ans);
	return 0;
}
