#include<bits/stdc++.h>
using namespace std;
bitset<1001> f[1001];
int n,m,ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		f[u][v]=1;
	}
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			if(f[i][j])
				f[i]|=f[j];
	for(int i=1;i<=n;i++)
		ans+=f[i].count();
	printf("%d",n*(n-1)/2-ans);
	return 0;
}
