#include<bits/stdc++.h>
#define mod 1000000003
using namespace std;
int t,n;
long long sum[1000001],f[1000001];
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=1000000;i++)
        sum[i]=(sum[i-1]+i)%mod;
    for(int i=1;i<=1000000;i++)
        f[i]=(f[i-1]+(sum[i]*sum[i])%mod)%mod;
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("%lld\n",f[n]);
    }
    return 0;
}
