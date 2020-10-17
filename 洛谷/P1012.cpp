#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n;
string a[21];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			string x=a[i],y=a[j];
			x+=a[j];
			y+=a[i];
			if(y>x)
			{
				string l;
				l=a[i];
				a[i]=a[j];
				a[j]=l;
			}
		}
	for(int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}
