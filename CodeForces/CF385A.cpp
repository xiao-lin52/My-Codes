#include<bits/stdc++.h>
using namespace std;
int n,c,a,b,ans;
int main()
{
	scanf("%d%d%d",&n,&c,&a);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&b);
		ans=max(ans,a-b);
		a=b;
	}
	if(ans<c)
		printf("0");
	else
		printf("%d",ans-c);
	return 0;
}
