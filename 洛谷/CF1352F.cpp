#include<bits/stdc++.h>
#define ll int
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll t,n1,n2,n3;
int main()
{
	t=read();
	while(t--)
	{
		n1=read();
		n2=read();
		n3=read();
		if(n1&&n3)
		{
			printf("0");
			for(int i=1;i<=n2-1;i++)
				printf("%d",i%2);
			if(n2%2==1)
			{
				for(int i=1;i<=n1;i++)
					printf("0");
				for(int i=0;i<=n3;i++)
					printf("1");
			}
			else
			{
				for(int i=1;i<=n3;i++)
					printf("1");
				for(int i=0;i<=n1;i++)
					printf("0");
			}
		}
		else
		{
			if(n2%2==0)
			{
				if(n1)
				{
					printf("0");
					for(int i=1;i<=n2;i++)
						printf("%d",i%2);
					for(int i=1;i<=n1;i++)
						printf("0");
				}
				else
				{
					printf("1");
					for(int i=0;i<=n2-1;i++)
						printf("%d",i%2);
					for(int i=1;i<=n3;i++)
						printf("1");
				}
			}
			else
			{
				if(n1)
				{
					printf("1");
					for(int i=0;i<=n2-1;i++)
						printf("%d",i%2);
					for(int i=1;i<=n1;i++)
						printf("0");
				}
				if(n3)
				{
					printf("0");
					for(int i=1;i<=n2;i++)
						printf("%d",i%2);
					for(int i=1;i<=n3;i++)
						printf("1");
				}
				if(!n1&&!n3)
				{
					printf("0");
					for(int i=1;i<=n2;i++)
						printf("%d",i%2);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
