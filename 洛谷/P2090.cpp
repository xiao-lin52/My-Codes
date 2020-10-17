#include<bits/stdc++.h>
using namespace std;
int n,step,flag,ans=1000000000;
void gcd(int x,int y)
{
	if(y==0)
	{
		if(x!=1)
			flag=1;
		step--;
		return;
	}
	else
	{
		if(x<y)
			swap(x,y);
		step+=x/y;
		gcd(y,x%y);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		step=flag=0;
		gcd(n,i);
		if(!flag)
			ans=min(ans,step);
	}
	printf("%d",ans);
	return 0;
}