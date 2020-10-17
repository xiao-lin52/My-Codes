#include<cstdio>
#include<queue>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[1000001];
int n,cnt,ans,a[10001],head[10001],in[10001],out[10001],f[10001];
queue<int> q;
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
void topo()
{
	for(int i=1;i<=n;i++)
		if(!in[i])
		{
			f[i]=a[i];
			q.push(i);
		}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			in[v]--;
			f[v]=f[v]>f[u]?f[v]:f[u];
			if(!in[v])
			{
				f[v]+=a[v];
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!out[i])
			ans=ans>f[i]?ans:f[i];
	printf("%d",ans);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%*d%d%d",&a[i],&v);
		while(v)
		{
			add_edge(v,i);
			in[i]++;
			out[v]++;
			scanf("%d",&v);
		}
	}
	topo();
	return 0;
}
