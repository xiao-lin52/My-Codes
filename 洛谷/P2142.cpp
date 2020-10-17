#include<iostream>
#include<string>
using namespace std;
string a,b;
int j,jw,x[10010],y[10010],ans[100000];
int main()
{
	cin>>a>>b;
	if(a.length()<b.length()||(a.length()==b.length()&&a<b))
	{
		string t;
		t=a;
		a=b;
		b=t;
		cout<<"-";
	}
	x[0]=a.length();
	y[0]=b.length();
	j=x[0]>y[0]? x[0]:y[0];
	for(int i=1;i<=x[0];i++)
		x[i]=a[x[0]-i]-'0';
	for(int i=1;i<=y[0];i++)
		y[i]=b[y[0]-i]-'0';
	for(int i=1;i<=j;i++)
	{
		ans[i]=x[i]-y[i]-jw;
		if(ans[i]<0)
		{
			ans[i]+=10;
			jw=1;
		}
		else
			jw=0;
	}
	while(ans[j]==0)
		j--;
	for(int i=j;i>=1;i--)
		cout<<ans[i];
	if(a==b)
		cout<<"0";
	return 0;
}