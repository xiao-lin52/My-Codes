#include<cstdio>
using namespace std;
int m,n,sum[10];
void Cal(int x)
{
	if(x==0) sum[0]++;
	for(int i=x;i>0;i/=10)
		sum[i%10]++;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++)
		Cal(i);
	for(int i=0;i<=9;i++)
		printf("%d ",sum[i]);
	return 0;
}
