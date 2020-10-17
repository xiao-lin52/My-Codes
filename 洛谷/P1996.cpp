#include<cstdio>
using namespace std;
int main()
{
	int n,m,j=0,i=0,s=0,a[100]={};
	scanf("%d%d",&n,&m);
	while(s!=n)
	{
		if(a[i%n]!=1)
			j++;	
		if(j==m)
		{
			printf("%d ",i%n+1);
			j=0;
			a[i%n]=1;
			s++;
		}
		i++;
	}
	return 0;
}