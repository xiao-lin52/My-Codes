#include<bits/stdc++.h>
#define mod 100003
using namespace std;
struct Edge
{
    int next;
    int to;
};
Edge edge[4000001];
int n,m,cnt,head[1000001],ans[1000001],f[1000001],visit[1000001];
queue<int> q;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].next=head[u];
    edge[cnt].to=v;
    head[u]=cnt;
}
void bfs()
{
    visit[1]=1;
    q.push(1);
    f[1]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!visit[v])
            {
                visit[v]=1;
                q.push(v);
                ans[v]=ans[u]+1;
            }
            if(ans[u]+1==ans[v])
                f[v]=(f[v]+f[u])%mod;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    bfs();
    for(int i=1;i<=n;i++)
        printf("%d\n",f[i]);
    return 0;
}
