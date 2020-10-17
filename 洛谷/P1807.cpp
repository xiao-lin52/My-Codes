#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v;
	int c;
};
int n,m,in[1501],b[1501];
queue<int> q;
vector<node> edge[1501];
vector<int> dis(1501,-1);
void topo()
{
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	dis[1]=0;
	b[1]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<edge[u].size();i++)
		{
			int x=edge[u][i].v,y=edge[u][i].c;
			in[x]--;
			if(b[u])
			{
				dis[x]=max(dis[x],dis[u]+y);
				b[x]=1;
			}
			if(!in[x])
				q.push(x);
		}
	}
	printf("%d",dis[n]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		node t;
		scanf("%d%d%d",&x,&y,&z);
		t.v=y;
		t.c=z;
		edge[x].push_back(t);
		in[y]++;
	}
	topo();
	return 0;
}
