#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",max(a+b,c+d));
	}
	return 0;
}
