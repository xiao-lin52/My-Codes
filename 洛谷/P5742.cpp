#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%*d%d%d",&a,&b);
        if(a+b>140&&a*7/10.0+b*3/10.0>80)
            printf("Excellent\n");
        else
            printf("Not excellent\n");
    }
    return 0;
}
