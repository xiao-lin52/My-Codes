#include<bits/stdc++.h>
using namespace std;
const int N=60;
int n, m, ans, sum, c[N], a[N][N], vis[N], suf[N];
void dfs(int x, int sum)
{
	if(sum+suf[x] <= ans)
		return;
	if(x == n+1)
	{
		ans = sum;
		return;
	}
	int flag = 1;
	for(int i = 1; i <= n; i++)
		if(a[x][i] && vis[i] == 1)
			flag = 0;
	if(a[x][x])
		flag = 0;
	if(flag)
	{
		vis[x] = 1;
		dfs(x+1, sum+c[x]);
		vis[x] = 0;
	}
	vis[x] = 2;
	dfs(x+1, sum);
	vis[x] = 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		sum += c[i];
	}
	for(int i = n; i >= 1; i--)
		suf[i] = suf[i+1]+c[i];
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		a[u][v] = a[v][u] = 1;
	}
	dfs(1, 0);
	printf("%d", sum-ans);
	return 0;
}