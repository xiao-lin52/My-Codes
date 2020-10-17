#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string a,b;
int ans,mid;
bool hw()
{
	for(int i=0;i<a.length();i++)
		if(a[i]!=a[a.length()-i-1])
			return false;
	return true;
}
void search()
{
	if(hw())
	{
		if(a.length()%2==0)
		{
			mid=a.length()/2;
			b=a;
			a="";
			for(int i=0;i<mid;i++)
				a+=b[i];
			search();
		}
	}
}
int main()
{
	cin>>a;
	search();
	ans=a.length();
	cout<<ans;
	return 0;
}
