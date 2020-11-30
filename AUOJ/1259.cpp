#include<bits/stdc++.h>
using namespace std;
double x,p[20];
int cnt;
void dfs(int step,int last,double s,int n)
{
	if(step==n+1)
	{
		cnt++;
		for(int i=last+1;i<=10;i++)
			s*=p[i];
		x+=s;
		return;
	}
	for(int i=last+1;i<=10&&i<=10-(n-step+1)+1;i++)
	{
		dfs(step+1,i,s*(1.0-p[i]),n);
		s*=p[i];
	}
}
int main()
{
	for(int i=0;i<=10;i++)
		scanf("%lf",&p[i]);
	dfs(1,0,1.0,8);
	dfs(1,0,1.0,9);
	dfs(1,0,1.0,10);
	x=x*(1.0-p[0]);
	printf("%.10lf\n%.10lf",x,(1.0-x)*(1.0-x));
	return 0;
}