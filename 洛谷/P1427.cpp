#include<cstdio>
using namespace std;
int i,a[101];
int main()
{
	do
		scanf("%d",&a[++i]);
	while(a[i]!=0);
	for(int j=i-1;j>0;j--)
		printf("%d ",a[j]);
	return 0;
}
