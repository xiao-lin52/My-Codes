#include<cstdio>
#include<queue>
#define Mod 80112002
using namespace std;
struct Edge
{
	int next;
	int to;
};
Edge edge[500001];
int n,m,cnt,ans,in[5001],out[5001],head[5001],f[5001];
queue<int>q;
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
			q.push(i);
			f[i]=1;
		}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			in[v]--;
			f[v]=(f[v]+f[u])%Mod;
			if(!in[v])
				q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		if(!out[i])
			ans=(ans+f[i])%Mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add_edge(a,b);
		in[b]++;
		out[a]++;
	}
	topo();
	printf("%d",ans);
	return 0;
}
