#include<cstdio>
using namespace std;
int n,s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			s++;
	printf("%d",s);
	return 0;
}
