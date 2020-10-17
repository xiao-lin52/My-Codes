#include<cstdio>
using namespace std;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(d<b)
	{
		d+=60;
		c--;
	}
	printf("%d %d",c-a,d-b);
	return 0;
}
