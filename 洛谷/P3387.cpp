#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[100001];
int x[100001],y[100001]; 
int n,m,s,a[10001],head[10001];
int cnt,cur,top,dfn[10001],low[10001],stack[10001],v[10001],b[10001];
int np[10001];
int ans,f[10001];
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
			v[stack[top]]=0;
			b[stack[top]]=cur;
			np[cur]+=a[stack[top]];
			top--;
		}
	}
}
void dfs(int x)
{
	if(f[x])
		return;
	int maxn=np[x];
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(!f[edge[i].to])
			dfs(edge[i].to);
		maxn=max(maxn,f[edge[i].to]+np[x]);
	}
	f[x]=maxn;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		add_edge(x[i],y[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	memset(head,-1,sizeof(head));
	memset(edge,0,sizeof(edge));
	s=0;
	for(int i=1;i<=m;i++)
		if(b[x[i]]!=b[y[i]])
			add_edge(b[x[i]],b[y[i]]);
	for(int i=1;i<=cur;i++)
	{
		dfs(i);
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}
