#include<cstdio>
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;;i++)
		if(i*i<=n)
			printf("%d ",i*i);
		else
			break;
	return 0;
}
