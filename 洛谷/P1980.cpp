#include<cstdio>
using namespace std;
int i,j,s,x,n;
int main()
{
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
		for(j=i;j>0;j/=10)
			if(j%10==x)
				s++;
	printf("%d",s);
	return 0;
}