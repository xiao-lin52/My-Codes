#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n/4;i++)
		if((n-i*4)%7==0)
		{
			for(int j=1;j<=i;j++)
				printf("4");
			for(int j=1;j<=(n-i*4)/7;j++)
				printf("7");
			return 0;
		}
	printf("-1");
	return 0;
}
