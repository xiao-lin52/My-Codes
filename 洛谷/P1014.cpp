#include<cstdio>
using namespace std;
int n,x,y,p;
int main()
{
	scanf("%d",&n);
	x=1;
	y=1;
	for(int i=1;i<n;i++)
	{
		if(p)
		{
			x++;
			y--;
			if(y==0)
			{
				y++;
				p=0;
			}
		}
		else
		{
			x--;
			y++;
			if(x==0)
			{
				x++;
				p=1;
			}
		}
	}
	printf("%d/%d",x,y);
	return 0;
}
