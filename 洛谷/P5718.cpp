#include<bits/stdc++.h>
using namespace std;
int n,a,ans=1001;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        ans=min(ans,a);
    }
    printf("%d",ans);
    return 0;
}
