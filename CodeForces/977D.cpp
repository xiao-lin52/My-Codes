#include<bits/stdc++.h>
using namespace std;
int n,tot,in[101],ans[101],edge[101][101];
long long a[101];
queue<int> q;
void topo()
{
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		ans[++tot]=u;
		for(int i=1;i<=n;i++)
			if(edge[u][i])
			{
				in[i]--;
				if(!in[i])
					q.push(i);
			}
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",a[ans[i]]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((a[i]*2==a[j])||(a[i]%3==0&&a[i]/3==a[j]))
			{
				edge[i][j]=1;
				in[j]++;
			}
	topo();
	return 0;
}
