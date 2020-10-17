#include<cstdio>
#define max(a,b) a>b?a:b
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[200001];
int n,m,cnt,head[100001],in[100001],f[100001];
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
void dfs(int u)
{
	int maxn=0;
	for(int i=head[u];i;i=edge[i].next)
	{
		if(!f[edge[i].to])
			dfs(edge[i].to);
		maxn=max(maxn,f[edge[i].to]);
	}
	f[u]=maxn+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(y,x);
		in[x]++;
	}
	for(int i=1;i<=n;i++)
		if(!in[i]&&!f[i])
			dfs(i);
	for(int i=1;i<=n;i++)
		printf("%d\n",f[i]);
	return 0;
}
