#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[200001];
int n,m,s,head[20001];
int cnt,top,cur,dfn[20001],low[20001],stack[20001],v[20001],b[20001];
void add_edge(int u,int v)
{
	edge[s].next=head[u];
	edge[s].to=v;
	head[u]=s;
	s++;
}
void tarjan(int x,int root)
{
	int son_cnt=0,flag=0;
	cnt++;
	dfn[x]=low[x]=cnt;
	stack[++top]=x;
	v[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
		if(!dfn[edge[i].to])
		{
			tarjan(edge[i].to,root);
			low[x]=min(low[x],low[edge[i].to]);
			if(low[edge[i].to]>=dfn[x]&&x!=root)
				flag=1;
			if(x==root)
				son_cnt++;
		}
		else
			if(v[edge[i].to])
				low[x]=min(low[x],dfn[edge[i].to]);
	if(son_cnt>=2)
		flag=1;
	if(flag)
		b[++cur]=x;
	if(dfn[x]!=low[x])
		while(stack[top+1]!=x)
		{
			v[stack[top]]=0;
			top--;
		}
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
			tarjan(i,i);
	sort(b+1,b+1+cur);
	printf("%d\n",cur);
	for(int i=1;i<=cur;i++)
		printf("%d ",b[i]);
	return 0;
}
