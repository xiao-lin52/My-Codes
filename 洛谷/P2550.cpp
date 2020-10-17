#include<cstdio>
using namespace std;
int n,a,s,standard[40],price[10];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=7;i++)
	{
		scanf("%d",&s);
		standard[s]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=7;j++)
		{
			scanf("%d",&a);
			if(standard[a])
				sum++;
		}
		price[8-sum]++;
	}
	for(int i=1;i<=7;i++)
		printf("%d ",price[i]);
	return 0;
}
