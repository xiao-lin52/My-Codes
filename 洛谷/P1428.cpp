#include<cstdio>
using namespace std;
int n,a[100];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=i-1;j>=0;j--)
			if(a[j]<a[i]) sum++;
		printf("%d ",sum);
	}
	return 0;
}
