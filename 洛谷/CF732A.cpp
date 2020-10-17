#include<cstdio>
using namespace std;
int k,r,i;
int main()
{
	scanf("%d%d",&k,&r);
	for(i=1;!(i*k%10==r||i*k%10==0);i++);
	printf("%d",i);
	return 0;
}
