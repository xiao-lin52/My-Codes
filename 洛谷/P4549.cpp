#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n,a,ans;
int gcd(int x,int y)
{
	while(x)
	{
		int t=x;
		x=y%x;
		y=t;
	}
	return y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		a=a>0 ? a:-a;
		ans=gcd(ans,a);
	}
	printf("%d",ans);
	return 0;
}