#include<cstdio>
#include<queue>
using namespace std;
int n,tot,s,sum=200001,t[200001],in[200001],ans[200001];
queue<int> q;
void dfs(int x)
{
	ans[x]=1;
	s++;
	if(!ans[t[x]])
	{
		dfs(t[x]);
	}
}
void topo()
{
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		ans[u]=1;
		tot++;
		q.pop();
		in[t[u]]--;
		if(!in[t[u]])
			q.push(t[u]);
	}
	for(int i=1;i<=n;i++)
		if(!ans[i])
		{
			s=0;
			dfs(i);
			sum=sum<s?sum:s;
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		in[t[i]]++;
	}
	topo();
	printf("%d",sum);
	return 0;
}
