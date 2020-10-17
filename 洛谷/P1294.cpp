#include<cstdio>
#define max(a,b) a>b?a:b
using namespace std;
int n,m,ans,map[21][21],visit[21];
void dfs(int x,int s)
{
	ans=max(ans,s);
	visit[x]=1;
	for(int i=1;i<=n;i++)
		if(map[x][i]&&!visit[i])
			dfs(i,s+map[x][i]);
	visit[x]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		map[u][v]=map[v][u]=c;
	}
	for(int i=1;i<=n;i++)
		dfs(i,0);
	printf("%d",ans); 
	return 0;
}
