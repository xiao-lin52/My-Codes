#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[101],prime[100001],b[100001];
void prime_find()
{
    b[0]=b[1]=1;
    for(int i=1;i<=m;i++)
    {
        if(!b[i])
            prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<=m;j++)
        {
            b[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        m=max(m,a[i]);
    }
    prime_find();
    for(int i=1;i<=n;i++)
        if(!b[a[i]])
            printf("%d ",a[i]);
    return 0;
}
