#include<cstdio>
#include<iostream>
using namespace std;
int n,step,a[10010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i)
			{
				for(int k=j;k>i;k--)
				{
					swap(a[k],a[k-1]);
					step++;
				}
				break;
			}
		}
	}
	printf("%d",step);
	return 0;
}
