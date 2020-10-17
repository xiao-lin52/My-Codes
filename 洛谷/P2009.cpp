#include<iostream>
#include<vector>
#define min(a,b) a<b?a:b
using namespace std;
int n,k,s,t,dis[101][101];
char t1,t2;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1000000;
	for(int i=1;i<=n;i++)
	{
		int t3;
		cin>>t3;
		if(i!=n)
			dis[i][i+1]=dis[i+1][i]=t3;
		else
			dis[i][1]=dis[1][i]=t3;
	}
	for(int i=1;i<=k;i++)
	{
		int a,b,c;
		cin>>t1>>t2>>c;
		a=t1-'A'+1;
		b=t2-'A'+1;
		if(dis[a][b]<c||dis[a][b]==1000000)
			dis[a][b]=dis[b][a]=c;
	}
	cin>>t1>>t2;
	s=t1-'A'+1;
	t=t2-'A'+1;
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	cout<<dis[s][t];
	return 0;
}