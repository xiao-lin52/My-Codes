#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
#define inf 1e9
using namespace std;
int n,m,q,p,t[201],a[201][201];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=inf;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		if(!t[i])
			p++;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		u++;
		v++;
		a[u][v]=a[v][u]=c;
	}
	for(int k=1;k<=p;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	scanf("%d",&q);
	while(q--)
	{
		int u,v,x,f=0;
		scanf("%d%d%d",&u,&v,&x);
		u++;
		v++;
		if(t[u]>x||t[v]>x)
		{
			printf("-1\n");
			continue;
		}
		while(t[p+1]<=x&&p<n)
		{
			p++;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					a[i][j]=min(a[i][j],a[i][p]+a[p][j]);
		}
		if(a[u][v]==inf)
			printf("-1\n");
		else
			printf("%d\n",a[u][v]);
	}
	return 0;
}
