#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[100001];
int t,n,m,cnt,tot,head[100001],in[100001],vis[100001],ans[100001];
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
void topo()
{
	priority_queue<int> q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		ans[++tot]=u;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			in[v]--;
			if(!in[v])
				q.push(v);
		}
	}
	if(tot<n)
		printf("Impossible!");
	else
		for(int i=n;i>=1;i--)
			printf("%d ",ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add_edge(y,x);
			in[x]++;
		}
		topo();
		memset(head,0,sizeof(head));
		memset(edge,0,sizeof(edge));
		memset(ans,0,sizeof(ans));
		memset(in,0,sizeof(in));
		memset(vis,0,sizeof(vis));
		cnt=tot=0;
	}
	return 0;
}
