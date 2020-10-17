#include<iostream>
#include<string>
using namespace std;
int n,m;
string a,maxn;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a.length()>maxn.length()||(a.length()==maxn.length()&&a>maxn))
		{
			maxn=a;
			m=i;
		}
	}
	cout<<m<<"\n"<<maxn;
	return 0;
}
