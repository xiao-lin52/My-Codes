#include<bits/stdc++.h>
using namespace std;
struct item
{
    double w;
    double v;
};
bool cmp(item a,item b)
{
    return a.v/a.w>b.v/b.w;
}
item a[101];
int n,m;
double s,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&a[i].w,&a[i].v);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(s+a[i].w<=m)
        {
            ans+=a[i].v;
            s+=a[i].w;
        }
        else
        {
            ans+=(m-s)*a[i].v/a[i].w;
            break;
        }
    }
    printf("%.2lf",ans);
    return 0;
}
