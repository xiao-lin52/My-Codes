#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int next;
	int to;
};
struct Que
{
	int next;
	int to;
	int id;
};
Edge edge[100001];
Que que[200001];
int n,m,cnt,res;
int head[50001],queh[50001],f[50001],fa[50001],v[50001],ans[100001],p[50001],sum[50001];
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	head[u]=cnt;
}
void add_que(int u,int v,int x)
{
	cnt++;
	que[cnt].next=queh[u];
	que[cnt].to=v;
	que[cnt].id=x;
	queh[u]=cnt;
}
int find(int x)
{
	return f[x]==x? f[x]:f[x]=find(f[x]);
}
void lca(int u,int father)
{
	fa[u]=father;
	for(int i=head[u];i;i=edge[i].next)
		if(edge[i].to!=father)
		{
			lca(edge[i].to,u);
			f[find(edge[i].to)]=find(u);
			v[edge[i].to]=1;
		}
	for(int i=queh[u];i;i=que[i].next)
		if(v[que[i].to])
			ans[que[i].id]=find(que[i].to);
}
void work(int u,int father)
{
	for(int i=head[u];i;i=edge[i].next)
		if(edge[i].to!=father)
		{
			work(edge[i].to,u);
			sum[u]+=sum[edge[i].to];
		}
	sum[u]+=p[u];
	res=max(res,sum[u]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	cnt=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_que(x,y,i);
		add_que(y,x,i);
	}
	lca(1,0);
	for(int i=1;i<=n;i++)
		for(int j=queh[i];j;j=que[j].next)
		{
			p[i]++;
			p[que[j].to]++;
			p[ans[que[j].id]]--;
			p[fa[ans[que[j].id]]]--;
		}
	for(int i=1;i<=n;i++)
		p[i]/=2;
	work(1,0);
	printf("%d",res);
	return 0;
}
