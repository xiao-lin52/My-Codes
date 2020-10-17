#include<bits/stdc++.h>
using namespace std;
vector<int> edge[20001];
int n,m,ans,num,s,dis[20001];
queue<int> q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(dis,0x3f3f3f,sizeof(dis));
    q.push(1);
    dis[1]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==ans)
        {
            s++;
            num=num<i? num:i;
        }
        if(dis[i]>ans)
        {
            ans=dis[i];
            s=1;
            num=i;
        }
    }
    printf("%d %d %d",num,ans,s);
    return 0;
}
