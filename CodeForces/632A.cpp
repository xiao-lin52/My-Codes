#include<cstring>
#include<iostream>
using namespace std;
int n,p;
long double s;
long long ans;
string a[100];
int main()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(a[i]=="halfplus")
			s+=0.5;
		ans+=p*s;
		s*=2;
	}
	cout<<ans;
	return 0;
}
