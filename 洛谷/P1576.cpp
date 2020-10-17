#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int to;
	int next;
	double w;
};
Edge edge[200001];
int n,m,s,t,cnt,head[2001],b[2001];
double dis[2001];
void add_edge(int u,int v,double c)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].w=c;
	head[u]=cnt;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		dis[i]=1000000000.0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		double z;
		scanf("%d%d%lf",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	scanf("%d%d",&t,&s);
	dis[s]=100.0;
	for(int i=1;i<=n;i++)
	{
		double minn=1000000000.0;
		int u=0;
		for(int j=1;j<=n;j++)
			if(minn>dis[j]&&!b[j])
			{
				minn=dis[j];
				u=j;
			}
		if(!u)
			break;
		b[u]=1;
		for(int j=head[u];j;j=edge[j].next)
			dis[edge[j].to]=min(dis[edge[j].to],dis[u]/(1.0-edge[j].w*0.01));
	}
	printf("%.8lf",dis[t]);
	return 0;
}
