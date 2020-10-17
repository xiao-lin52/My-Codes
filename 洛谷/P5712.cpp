#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    printf("Today, I ate %d apple",n);
    if(n>1)
        printf("s.");
    else
        printf(".");
    return 0;
}
