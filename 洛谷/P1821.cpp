#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct Edge
{
	int next;
	int to;
	int w;
};
Edge edge1[100001],edge2[100001];
vector<int>head1(1001,-1);
vector<int>head2(1001,-1);
vector<int>dis1(1001,1000000);
vector<int>dis2(1001,1000000);
queue<int>q;
int n,m,x,cnt,ans;
void add_edge(int u,int v,int c)
{
	edge1[cnt].next=head1[v];
	edge1[cnt].to=u;
	edge1[cnt].w=c;
	edge2[cnt].next=head2[u];
	edge2[cnt].to=v;
	edge2[cnt].w=c;
	head1[v]=cnt;
	head2[u]=cnt;
	cnt++;
}
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a,b,c);
	}
	dis1[x]=0;
	q.push(x);
	while(!q.empty())
	{
		for(int i=head1[q.front()];i!=-1;i=edge1[i].next)
			if(dis1[edge1[i].to]>dis1[q.front()]+edge1[i].w)
			{
				dis1[edge1[i].to]=dis1[q.front()]+edge1[i].w;
				q.push(edge1[i].to);
			}
		q.pop();
	}
	dis2[x]=0;
	q.push(x);
	while(!q.empty())
	{
		for(int i=head2[q.front()];i!=-1;i=edge2[i].next)
			if(dis2[edge2[i].to]>dis2[q.front()]+edge2[i].w)
			{
				dis2[edge2[i].to]=dis2[q.front()]+edge2[i].w;
				q.push(edge2[i].to);
			}
		q.pop();
	}
	for(int i=1;i<=n;i++)
		ans=ans>dis1[i]+dis2[i]? ans:dis1[i]+dis2[i];
	printf("%d",ans);
	return 0;
}
