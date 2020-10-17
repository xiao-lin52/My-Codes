#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string n;
int s;
int main()
{
	cin>>n;
	for(int i=1;i<n.length();i++)
		if(n[i]!=n[i-1])
			s++;
	if(n[n.length()-1]=='0')
		s++;
	printf("%d",s);
	return 0;
}
