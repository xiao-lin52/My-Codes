#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int n,m,ans,a[1001][1001],a2[1001][1001],dis1[1001],b1[1001],b2[1001],dis2[1001];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=a2[i][j]=inf;
    for(int i=2;i<=n;i++)
        dis1[i]=dis2[i]=inf;
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        a[u][v]=min(a[u][v],c);
        a2[v][u]=min(a2[v][u],c);
    }
    dis1[1]=dis2[1]=0;
    for(int i=1;i<=n;i++)
    {
        int minn=inf,u=0;
        for(int j=1;j<=n;j++)
            if(dis1[j]<minn&&!b1[j])
            {
                minn=dis1[j];
                u=j;
            }
        b1[u]=1;
        for(int j=1;j<=n;j++)
            if(!b1[j])
                dis1[j]=min(dis1[j],dis1[u]+a[u][j]);
    }
    for(int i=1;i<=n;i++)
    {
        int minn=inf,u=0;
        for(int j=1;j<=n;j++)
            if(dis2[j]<minn&&!b2[j])
            {
                minn=dis2[j];
                u=j;
            }
        b2[u]=1;
        for(int j=1;j<=n;j++)
            if(!b2[j])
                dis2[j]=min(dis2[j],dis2[u]+a2[u][j]);
    }
    for(int i=1;i<=n;i++)
        ans+=dis1[i]+dis2[i];
    printf("%d",ans);
    return 0;
}
