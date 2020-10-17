#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,ans=inf,f[201],u[101],v[101],c[101],e[201][201],p[101],dis[201][201],l[101][101],r[101][101];
int find(int x)
{
	return f[x]==x?f[x]:f[x]=find(f[x]);
}
int main()
{
//	freopen("out.csc","w",stdout);
	scanf("%d",&m);
	memset(dis,inf,sizeof(dis));
	memset(e,inf,sizeof(e));
	for(int i=1;i<=2*m;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int s,w,n1,n2,y;
		scanf("%d%d%d%d",&s,&w,&n1,&n2);
		u[s]=2*s-1;
		v[s]=2*s;
		c[s]=w;
		for(int j=1;j<=n1;j++)
		{
			scanf("%d",&y);
			l[s][y]=1;
		}
		for(int j=1;j<=n2;j++)
		{
			scanf("%d",&y);
			r[s][y]=1;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i!=j)
			{
				if(l[i][j]&&l[j][i])
					f[find(u[i])]=find(u[j]);
				if(l[i][j]&&r[j][i])
					f[find(u[i])]=find(v[j]);
				if(r[i][j]&&l[j][i])
					f[find(v[i])]=find(u[j]);
				if(r[i][j]&&r[j][i])
					f[find(v[i])]=find(v[j]);
			}
	for(int i=1;i<=2*m;i++)
		if(f[i]==i)
			p[i]=++n;
	for(int i=1;i<=m;i++)
	{
		u[i]=p[find(u[i])];
		v[i]=p[find(v[i])];
		dis[u[i]][v[i]]=dis[v[i]][u[i]]=e[u[i]][v[i]]=e[v[i]][u[i]]=c[i];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
			for(int j=1;j<i;j++)
				if(e[i][k]!=inf&&e[k][j]!=inf)
					ans=min(ans,dis[i][j]+e[i][k]+e[k][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	printf("%d",ans);
	return 0;
}
