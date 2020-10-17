#include<cstdio>
using namespace std;
int l,r,sum;
int main()
{
	scanf("%d%d",&l,&r);
	for(int i=l;i<=r;i++)
		for(int j=i;j>0;j/=10)
			if(j%10==2)
				sum++;
	printf("%d",sum);
	return 0;
}
