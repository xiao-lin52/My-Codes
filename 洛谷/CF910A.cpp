#include<bits/stdc++.h>
using namespace std;
int n,d,dis[101],b[101],a[101][101];
string s;
int main()
{
	memset(a,0x3f3f3f,sizeof(a));
	memset(dis,0x3f3f3f,sizeof(dis));
	cin>>n>>d>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='1')
			for(int j=i+1;j<=i+d&&j<n;j++)
				if(s[j]=='1')
					a[i+1][j+1]=1;
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int u=0,minn=1000000000;
		for(int j=1;j<=n;j++)
			if(dis[j]<minn&&!b[j])
			{
				minn=dis[j];
				u=j;
			}
		if(!u)
			break;
		b[u]=1;
		for(int v=1;v<=n;v++)
			dis[v]=min(dis[v],dis[u]+a[u][v]);
	}
	if(b[n])
		printf("%d",dis[n]);
	else
		printf("-1");
	return 0;
}
