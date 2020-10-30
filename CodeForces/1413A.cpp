#include<bits/stdc++.h>
using namespace std;
int t, n, a[110],ans[110];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        memset(a,0,sizeof(a));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 2; i <= n;i+=2)
        {
            ans[i] = -a[i - 1];
            ans[i - 1] = a[i];
        }
        for(int i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}