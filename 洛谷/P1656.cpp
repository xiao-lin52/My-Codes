#include<cstdio>
#include<algorithm>
using namespace std;
struct Edge
{
	int next;
	int to;
};
struct Ans
{
	int a;
	int b;
};
bool cmp(Ans x,Ans y)
{
	if(x.a!=y.a) return x.a<y.a;
	if(x.b!=y.b) return x.b<y.b;
}
Edge edge[10001];
Ans ans[5001];
int n,m,cnt,head[151];
int tot,cur,dfn[151],low[151];
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
void tarjan(int u,int f)
{
	tot++;
	dfn[u]=low[u]=tot;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v])
		{
			tarjan(v,u);
			if(v!=f)
				low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])
			{
				cur++;
				ans[cur].a=min(u,v);
				ans[cur].b=max(u,v);
			}
		}
		else
			if(v!=f)
				low[u]=min(low[u],dfn[v]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	tarjan(1,0);
	sort(ans+1,ans+1+cur,cmp);
	for(int i=1;i<=cur;i++)
		printf("%d %d\n",ans[i].a,ans[i].b);
	return 0;
}
