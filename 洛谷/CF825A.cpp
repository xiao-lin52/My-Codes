#include<bits/stdc++.h>
using namespace std;
int n,s;
char a;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a=='1')
			s++;
		else
		{
			cout<<s;
			s=0;
		}
	}
	cout<<s;
	return 0;
}
