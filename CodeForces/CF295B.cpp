#include<bits/stdc++.h>
using namespace std;
int n,dis[501][501],x[501],b[501];
long long sum[501];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int k=n;k>=1;k--)
	{
		b[x[k]]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][x[k]]+dis[x[k]][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(b[i]&&b[j])
					sum[k]+=dis[i][j];
	}
	for(int i=1;i<=n;i++)
		cout<<sum[i]<<" ";
	return 0;
}
