#include<bits/stdc++.h>
using namespace std;
int n,a,maxn=0,minn=1001;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        maxn=max(maxn,a);
        minn=min(minn,a);
    }
    printf("%d",maxn-minn);
    return 0;
}
