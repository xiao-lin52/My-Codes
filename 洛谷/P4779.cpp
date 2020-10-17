#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	int dis=2147483647;
};
struct cmp
{
	bool operator() (const node a,const node b)
	{
		return a.dis>b.dis;
	}
};
struct Edge
{
	int next;
	int to;
	int w;
};
node a[100001];
Edge edge[200001];
int n,m,s,cnt,head[100001],b[100001],v[100001];
priority_queue<node,vector<node>,cmp> q;
void add_edge(int u,int v,int c)
{
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].w=c;
	head[u]=cnt;
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++)
		a[i].data=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		add_edge(u,v,c);
	}
	a[s].dis=0;
	v[s]=1;
	q.push(a[s]);
	while(q.size())
	{
		node x=q.top();
		q.pop();
		b[x.data]=1;
		if(x.dis>a[x.data].dis)
			continue;
		for(int j=head[x.data];j;j=edge[j].next)
		{
			int y=edge[j].to,z=edge[j].w;
			if(a[y].dis>a[x.data].dis+z&&!b[y])
			{
				a[y].dis=a[x.data].dis+z;
				q.push(a[y]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i].dis);
	return 0;
}
