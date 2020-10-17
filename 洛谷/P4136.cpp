#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	while(n)
	{
		if(n*n%2)
			printf("Bob\n");
		else
			printf("Alice\n");
		scanf("%d",&n);
	}
	return 0;
}
