#include<cstdio>
using namespace std;
int n,m,y,s;
int main()
{
	scanf("%d%d",&n,&m);
	s=n/m;
	y=n%m;
	for(int i=1;i<=m-y;i++)
		printf("%d ",s);
	for(int i=m-y+1;i<=m;i++)
		printf("%d ",s+1);
	return 0;
}