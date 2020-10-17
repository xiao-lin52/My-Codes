#include<bits/stdc++.h>
using namespace std;
long long t,n,p,flag;
inline void check(long long x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==2)
			flag=1;
		if(x%i==0)
			p=1;
		if(p&&flag)
			break;
	}
}
int main()
{
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		flag=p=0;
		scanf("%lld",&n);
		if(n%2==0)
			if(n==2)
				printf("1\n");
			else
				printf("2\n");
		else
		{
			check(n);
			if(!p)
				printf("1\n");
			if(p&&!flag)
				printf("2\n");
			if(p&&flag)
				printf("3\n");
		}
	}
	return 0;
}
