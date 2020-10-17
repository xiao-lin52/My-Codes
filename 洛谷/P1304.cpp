#include<cstdio>
using namespace std;
int n,k,prime[10001],b[10001]={1,1};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
			prime[++k]=i;
		for(int j=1;j<=k&&i*prime[j]<=n;j++)
		{
			b[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
	for(int i=4;i<=n;i+=2)
	{
		for(int j=1;j<=k;j++)
			for(int l=1;l<=k;l++)
			{
				if(prime[j]+prime[l]==i)
				{
					printf("%d=%d+%d\n",i,prime[j],prime[l]);
					goto f;
				}
				if(prime[j]+prime[l]>i)
					break;
			}
		f:;
	}
	return 0;
}
