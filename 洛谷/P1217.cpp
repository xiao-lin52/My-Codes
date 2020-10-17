#include<cstdio>
#include<cmath>
using namespace std;
int a,b,wa,wb;
bool prime(int x)
{
	if(x<2)
		return false;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
void dfs(int num,int x,int w)
{
	if(x==w)
	{
		if(num>b||num<a)
			return;
		if(prime(num))
			printf("%d\n",num);
		return;
	}
	if(x<w/2.0)
	{
		for(int i=0;i<=9;i++)
			dfs(num*10+i,x+1,w);
	}
	else
		dfs(num*10+num%int(pow(10,x*2-w+1))/pow(10,x*2-w),x+1,w);
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int temp=a;temp>0;temp/=10)
		wa++;
	for(int temp=b;temp>0;temp/=10)
		wb++;
	for(int i=wa;i<=wb;i++)
		for(int j=1;j<=9;j+=2)
			dfs(j,1,i);
	return 0;
}
