#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[50001];
int n,m,s,head[10001];
int cnt,k,ans,dfn[10001],low[10001],stack[10001],v[10001];
void tarjan(int x)
{
	cnt++;
	dfn[x]=low[x]=cnt;
	stack[++k]=x;
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
		int flag=0;
		while(stack[k]!=x)
		{
			flag=1;
			v[stack[k]]=0;
			k--;
		}
		v[x]=0;
		k--;
		if(flag)
			ans++;
	}
}
void add_edge(int u,int v)
{
	edge[s].next=head[u];
	edge[s].to=v;
	head[u]=s;
	s++;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add_edge(a,b);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	printf("%d",ans);
	return 0;
}
