#include<cstdio>
using namespace std;
int m,s,t,opt[300001];
int main()
{
	scanf("%d%d%d",&m,&s,&t);
	for(int i=1;i<=t;i++)
	{
		if(m>=10)
		{
			opt[i]=opt[i-1]+60;
			m-=10;
		}
		else
		{
			opt[i]=opt[i-1];
			m+=4;
		}
	}
	for(int i=1;i<=t;i++)
	{
		if(opt[i-1]+17>=opt[i])
			opt[i]=opt[i-1]+17;
		if(opt[i]>=s)
		{
			printf("Yes\n%d",i);
			return 0;
		}
	}
	printf("No\n%d",opt[t]);
	return 0;
}
