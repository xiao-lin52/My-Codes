#include<cstdio>
#include<cstring>
using namespace std;
int m,p,len;
char n[1001];
void writen(int x)
{
	if(x>=0)
	{
		if(n[len-1-x]!='0')
		{
			if(p)
				printf("+");
			printf("%c*%d^%d",n[len-1-x],m,x);
			p=1;
		}
		writen(x-1);
	}
	else
		return;
}
int main()
{
	scanf("%d%s",&m,n);
	len=strlen(n);
	writen(len-1);
	return 0;
}