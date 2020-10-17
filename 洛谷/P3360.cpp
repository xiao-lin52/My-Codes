#include<bits/stdc++.h>
using namespace std;
struct node
{
	int t;
	int x;
	int w[31];
	int c[31];
};
node p[601];
int t,cnt,v[601],fa[301],lson[301],rson[301],dp[301][601];
void build(int u,int father)
{
	fa[u]=father;
	if(!p[u].x)
	{
		int t=0;
		for(int i=u+1;i<=cnt;i++)
			if(!v[i])
			{
				t++;
				build(i,u);
				v[i]=1;
				if(t==1)
					lson[u]=i;
				else
				{
					rson[u]=i;
					break;
				}
			}
	}
}
int dfs(int u,int k)
{
	if(k<=0)
		return 0;
	if(!u)
		return dp[u][k]=0;
	if(dp[u][k])
		return dp[u][k];
	for(int j=0;j<=k;j++)
		dp[u][k]=max(dp[u][k],dfs(lson[u],j-p[lson[u]].t*2)+dfs(rson[u],k-j-p[rson[u]].t*2));
	return dp[u][k];
}
int main()
{
	scanf("%d",&t);
	while(++cnt&&scanf("%d%d",&p[cnt].t,&p[cnt].x)!=EOF)
		for(int i=1;i<=p[cnt].x;i++)
		{
			scanf("%d%d",&p[cnt].w[i],&p[cnt].c[i]);
			for(int j=t;j>=p[cnt].c[i];j--)
				dp[cnt][j]=max(dp[cnt][j],dp[cnt][j-p[cnt].c[i]]+p[cnt].w[i]);
		}
	build(1,0);
	for(int i=1;i<=cnt;i++)
		if(!fa[i])
		{
			printf("%d",dfs(i,t-p[i].t*2-1));
			break;
		}
	return 0;
}
