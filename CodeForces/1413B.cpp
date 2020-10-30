#include<bits/stdc++.h>
namespace IO
{
    template <typename T> inline void read(T &x)
    {
        x=0;
        register int f=1;
        register char c=getchar();
        while(c<'0'||c>'9')
        {
            if(c=='-') f=-1;
            c=getchar();
        }
        while(c>='0'&&c<='9')
            x=x*10+c-'0',c=getchar();
        x*=f;
    }
}
using namespace IO;
using namespace std;
int t,n,m,a[510][510],b[510][510],p[250010];
int main()
{
    read(t);
    while(t--)
    {
        read(n);
        read(m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                read(a[i][j]);
                p[a[i][j]]=i;
            }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                read(b[i][j]);
                if(!(i^1))
                {
                    for(int k=1;k<=m;k++)
                        printf("%d ",a[p[b[i][j]]][k]);
                    printf("\n");
                }
            }
        }
    }
    return 0;
}