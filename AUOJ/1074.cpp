#include<bits/stdc++.h>
using namespace std;
string a;
int s;
int main()
{
	cin>>a;
	for(int i=0;i<a.length();i++)
		if(a[i]=='1')
			s++;
	cout<<s;
	return 0;
}