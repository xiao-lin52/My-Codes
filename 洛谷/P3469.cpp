#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[1000001];
int n,m,cnt,head[100001];
int tot,root,dfn[100001],low[100001];
int size[100001];
long long ans[100001];
void add_edge(int u,int v)
{
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
	cnt++;
}
void tarjan(int x)
{
	int flag=0,sum=0,v=0;
	tot++;
	dfn[x]=low[x]=tot;
	size[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(!dfn[edge[i].to])
		{
			tarjan(edge[i].to);
			size[x]+=size[edge[i].to];
			low[x]=min(low[x],low[edge[i].to]);
			if(low[edge[i].to]>=dfn[x])
			{
				ans[x]+=(long long)size[edge[i].to]*(n-size[edge[i].to]);
				sum+=size[edge[i].to];
				flag++;
				if(x!=root||flag>1)
					v=1;
			}
		}
		else
			low[x]=min(low[x],dfn[edge[i].to]);
	}
	if(v)
		ans[x]+=(long long)(n-sum-1)*(sum+1)+(n-1);
	else
		ans[x]=2*(n-1);
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
		{
			root=i;
			tarjan(i);
		}
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
