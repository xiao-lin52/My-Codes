#include<iostream>
#include<string>
using namespace std;
string a,b;
int p=1,j,bw,jw,x[2001],y[2001],ans[4000001];
int main()
{
	cin>>a>>b;
	x[0]=a.length();
	y[0]=b.length();
	if(a[0]=='-')
	{
		p=0-p;
		for(int i=1;i<a.length();i++)
			a[i-1]=a[i];
		x[0]--;
	}
	if(b[0]=='-')
	{
		p=0-p;
		for(int i=1;i<b.length();i++)
			b[i-1]=b[i];
		y[0]--;
	}
	if(p==-1)
		cout<<"-";
	for(int i=1;i<=x[0];i++)
		x[i]=a[x[0]-i]-'0';
	for(int i=1;i<=y[0];i++)
		y[i]=b[y[0]-i]-'0';
	j=x[0]+y[0];
	for(int i=1;i<=y[0];i++)
	{
		for(int k=1;k<=x[0];k++)
		{
			ans[i+k-1]+=x[k]*y[i]%10;
			ans[i+k]+=x[k]*y[i]/10;
		}
	}
	for(int i=1;i<=j;i++)
		if(ans[i]>=10)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	while(ans[j]==0&&j>1)
		j--;
	for(int i=j;i>=1;i--)
		cout<<ans[i];
	return 0;
}
