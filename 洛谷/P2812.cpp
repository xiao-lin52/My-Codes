#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[5000001];
int n,m,cnt,head[10001],x[5000001],y[5000001];
int tot,cur,top,dfn[10001],low[10001],stack[10001],vis[10001];
int p[10001],color[10001],in[10001],out[10001];
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
	stack[++top]=u;
	vis[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
			if(vis[v])
				low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		cur++;
		while(stack[top+1]!=u)
		{
			p[cur]++;
			color[stack[top]]=cur;
			vis[stack[top]]=0;
			top--;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		while(v)
		{
			m++;
			x[m]=i;
			y[m]=v;
			add_edge(i,v);
			scanf("%d",&v);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	cnt=0;
	memset(head,0,sizeof(head));
	memset(edge,0,sizeof(edge));
	for(int i=1;i<=m;i++)
		if(color[x[i]]!=color[y[i]])
		{
			add_edge(color[x[i]],color[y[i]]);
			out[color[x[i]]]++;
			in[color[y[i]]]++;
		}
	int s1=0,s2=0;
	for(int i=1;i<=cur;i++)
	{
		if(!in[i])
			s1++;
		if(!out[i])
			s2++;
	}
	if(cur==1)
		printf("1\n0");
	else
		printf("%d\n%d",s1,max(s1,s2));
	return 0;
}
