#include<bits/stdc++.h>
using namespace std;
int n,ans,ls[1000001],rs[1000001],in[1000001];
void dfs(int x,int depth)
{
    ans=max(ans,depth);
    if(ls[x])
        dfs(ls[x],depth+1);
    if(rs[x])
        dfs(rs[x],depth+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&ls[i],&rs[i]);
        in[ls[i]]++;
        in[rs[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(!in[i])
        {
            dfs(i,1);
            break;
        }
    printf("%d",ans);
    return 0;
}
