#include<bits/stdc++.h>
using namespace std;
int n,m,ans,dis[101][101];
int main()
{
	scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        dis[u][v]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=(dis[i][k]&dis[k][j])|dis[i][j];
    for(int i=1;i<=n;i++)
    {
        int s=0;
        for(int j=1;j<=n;j++)
            s+=dis[i][j]|dis[j][i];
        if(s==n-1)
            ans++;
    }
    printf("%d",ans);
	return 0;
}
