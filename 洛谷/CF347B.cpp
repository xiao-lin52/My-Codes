#include<cstdio>
using namespace std;
int n,s,ans,a[100001];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==i)
			s++;
	}
	if(s==n)
	{
		printf("%d",s);
		return 0;
	}
	for(int i=0;i<n;i++)
		if(i==a[a[i]]&&i!=a[i])
		{
			printf("%d",s+2);
			return 0;
		}
	printf("%d",s+1);
	return 0;
}
