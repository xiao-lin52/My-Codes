#include<cstdio>
using namespace std;
int n,sum,a[10];
int main()
{
	for(int i=0;i<10;i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=0;i<10;i++)
		if(n+30>=a[i]) sum++;
	printf("%d",sum);
	return 0;
}
