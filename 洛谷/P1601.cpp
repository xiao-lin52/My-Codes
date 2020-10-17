#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string a,b;
int j,jw,x[501],y[501],sum[502];
int main()
{
	cin>>a>>b;
	x[0]=a.length();
	y[0]=b.length();
	j=x[0]>y[0]? x[0]:y[0];
	for(int i=1;i<=x[0];i++)
		x[i]=a[x[0]-i]-'0';
	for(int i=1;i<=y[0];i++)
		y[i]=b[y[0]-i]-'0';
	for(int i=1;i<=j;i++)
	{
		sum[i]=(x[i]+y[i]+jw)%10;
		jw=(x[i]+y[i]+jw)/10;
	}
	if(jw)
		sum[++j]=jw;
	for(int i=j;i>=1;i--)
		printf("%d",sum[i]);
	return 0;
}
