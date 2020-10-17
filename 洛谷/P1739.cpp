#include<cstdio>
using namespace std;
int top;
char b;
int main()
{
	scanf("%c",&b);
	while(b!='@')
	{
		if(b=='(')
			top++;
		if(b==')')
			if(top==0)
			{
				printf("NO");
				return 0;
			}
			else
				top--;
		scanf("%c",&b);
	}
	if(top==0)
		printf("YES");
	else
		printf("NO");
	return 0;
}
