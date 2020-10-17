#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,u[6001],v[6001],c[6001],dis[2001],b[2001];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
        memset(b,0,sizeof(b));
		k=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			k++;
			scanf("%d%d%d",&u[k],&v[k],&c[k]);
			if(c[k]>=0)
			{
				k++;
				u[k]=v[k-1];
				v[k]=u[k-1];
				c[k]=c[k-1];
			}
		}
		dis[1]=0;
		b[1]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				if(b[u[j]])
				{
					dis[v[j]]=min(dis[v[j]],dis[u[j]]+c[j]);
					b[v[j]]=1;
				}
		for(int i=1;i<=k;i++)
			if((b[u[i]]||b[v[i]])&&dis[v[i]]>dis[u[i]]+c[i])
			{
				printf("YE5\n");
				goto l;
			}
		printf("N0\n");
		l:;
	}
	return 0;
}
