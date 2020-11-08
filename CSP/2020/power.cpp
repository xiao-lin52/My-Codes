#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
int n,k,ans[100];
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n&1)
		printf("-1");
	else
	{
		for(;n;n-=lowbit(n))
			ans[++k]=lowbit(n);
		for(int i=k;i>=1;i--)
			printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
