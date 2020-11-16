#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,n,mon[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll check_year_special(ll x)
{
	if(x<0)
		if((-x)%4==1)
			return 366;
		else
			return 365;
	else
		if(x%4==0)
			return 366;
		else
			return 365;
}
ll check_month_special(ll x,ll y)
{
	if(check_year_special(x)==366&&y==2)
		return 29;
	else
		return mon[y];
}
ll check_year(ll x)
{
	if(x%400==0||(x%4==0&&x%100!=0))
		return 366;
	else
		return 365;
}
ll check_month(ll x,ll y)
{
	if(check_year(x)==366&&y==2)
		return 29;
	else
		return mon[y];
}
int main()
{
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&n);
		if(n<=2299160)
		{
			ll y=n/1461*4-4713,m=1,flag=0;
			n%=1461;
			if(y>=0)
			{
				flag=1;
				y++;
			}
			while(n>=check_year_special(y))
			{
				n-=check_year_special(y++);
				if(y==0)
				{
					flag=1;
					y++;
				}
			}
			while(n>=check_month_special(y,m))
				n-=check_month_special(y,m++);
			if(flag)
				printf("%lld %lld %lld\n",n+1,m,y);
			else
				printf("%lld %lld %lld BC\n",n+1,m,-y);
		}
		if(2299160<n)
		{
			n-=2299161;
			if(n<=16)
				printf("%lld 10 1582\n",n+15);
			if(16<n&&n<=46)
				printf("%lld 11 1582\n",n-16);
			if(46<n&&n<=77)
				printf("%lld 12 1582\n",n-46);
			if(77<n)
			{
				n-=78;
				ll y=1583+n/146097*400,m=1;
				n%=146097;
				while(n>=check_year(y))
					n-=check_year(y++);
				while(n>=check_month(y,m))
					n-=check_month(y,m++);
				printf("%lld %lld %lld\n",n+1,m,y);
			}
		}
	}
	return 0;
}