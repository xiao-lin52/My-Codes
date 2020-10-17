#include<bits/stdc++.h>
using namespace std;
struct node
{
	int w;
	int s;
};
node p[501];
stack<int> q;
int t,cnt,v[201],fa[101],lson[101],rson[101],dp[101][601];
void build(int u,int father)
{
	fa[u]=father;
	if(!p[u].s)
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
	if(!lson[u]&&!rson[u])
		return dp[u][k]=min(k/5,p[u].s);
	for(int j=0;j<=k;j++)
		dp[u][k]=max(dp[u][k],dfs(lson[u],j-p[lson[u]].w*2)+dfs(rson[u],k-j-p[rson[u]].w*2));
	return dp[u][k];
}
int main()
{
	scanf("%d",&t);
	while(++cnt&&scanf("%d%d",&p[cnt].w,&p[cnt].s)!=EOF);
	build(1,0);
	for(int i=1;i<=cnt;i++)
		if(!fa[i])
		{
			printf("%d",dfs(i,t-p[i].w*2-1));
			break;
		}
	return 0;
}
