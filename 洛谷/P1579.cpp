#include<cstdio>
#include<cmath>
using namespace std;
int n,a,b,k;
bool prime(int x)
{
	if(x<=1) return false;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
void dfs(int x,int step)
{
	if(step==3)
	{
		if(prime(n-a-b))
		{
			printf("%d %d %d",a,b,n-a-b);
			k=1;
			return;
		}
	}
	else
	{
		for(int i=x;i<=n/3&&!k;i++)
		{
			if(prime(i))
			{
				if(step==1)
					a=i;
				else
					b=i;
				dfs(i,step+1);
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(2,1);
	return 0;
}
