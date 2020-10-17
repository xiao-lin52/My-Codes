#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[50001];
int n,m,s,x[50001],y[50001],head[10001];
int cnt,cur,top,dfn[10001],low[10001],stack[10001],v[10001],color[10001],p[10001];
int ans,flag,b[10001];
void add_edge(int u,int v)
{
	edge[s].next=head[u];
	edge[s].to=v;
	head[u]=s;
	s++;
}
void tarjan(int x)
{
	cnt++;
	dfn[x]=low[x]=cnt;
	stack[++top]=x;
	v[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
		if(!dfn[edge[i].to])
		{
			tarjan(edge[i].to);
			low[x]=min(low[x],low[edge[i].to]);
		}
		else
			if(v[edge[i].to])
				low[x]=min(low[x],dfn[edge[i].to]);
	if(dfn[x]==low[x])
	{
		cur++;
		while(stack[top+1]!=x)
		{
			color[stack[top]]=cur;
			p[cur]++;
			v[stack[top]]=0;
			top--;
		}
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		add_edge(x[i],y[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	s=0;
	memset(head,-1,sizeof(head));
	memset(edge,0,sizeof(edge));
	for(int i=1;i<=m;i++)
		if(color[x[i]]!=color[y[i]])
		{
			add_edge(color[x[i]],color[y[i]]);
			b[color[x[i]]]++;
		}
	for(int i=1;i<=cur;i++)
		if(!b[i])
		{
			if(flag)
			{
				printf("0");
				return 0;
			}
			flag=1;
			ans=p[i];
		}
	printf("%d",ans);
	return 0;
}