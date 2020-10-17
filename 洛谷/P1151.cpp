#include<cstdio>
using namespace std;
int sub1,sub2,sub3,k,i,q;
int main()
{
	scanf("%d",&k);
	for(i=10000;i<=30000;i++)
	{
		sub1=i/100;
		sub2=i%10000/10;
		sub3=i%1000;
		if(sub1%k==0&&sub2%k==0&&sub3%k==0)
		{
			q=1;
			printf("%d\n",i);
		}
	}
	if(!q) printf("No");
	return 0;
}
