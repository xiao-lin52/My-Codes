#include<cstdio>
#include<cmath>
using namespace std;
int judge(int y)
{
	if(y%100==0&&y%400==0) return 1;
	if(y%100!=0&&y%4==0) return 1;
	return 0;
}
int t,y,m,d,h,min,s,w,fu,month[2][13]={{0,31,59,90,120,151,181,212,243,273,304,334,365},{0,31,60,91,121,152,182,213,244,274,305,335,366}};
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d%d%d%d%d%d",&w,&y,&m,&d,&h,&min,&s);
		long long n=pow(2,w-1)-1;
		n+=h*3600+min*60+s;
		fu=n%86400;
		n=n/86400;
		n+=d;
		n+=month[judge(y)][m-1];
		long long sum=0;
		while(sum+365+judge(y)<n)
			sum+=365+judge(y++);
		printf("%d ",y);
		n=n-sum;
		sum=0;
		m=1;
		while(month[judge(y)][m]<n)
			sum=month[judge(y)][m++];
		printf("%d ",m);
		n-=sum;
		printf("%d ",n);
		printf("%d ",fu/3600);
		printf("%d ",fu%3600/60);
		printf("%d \n",fu%3600%60);
	}
	return 0;
}