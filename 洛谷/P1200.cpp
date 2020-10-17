#include<iostream>
#include<string>
using namespace std;
string a,b;
int s1=1,s2=1;
int main()
{
	cin>>a>>b;
	for(int i=0;i<a.length();i++)
		s1=s1*(a[i]-'A'+1)%47;
	for(int i=0;i<b.length();i++)
		s2=s2*(b[i]-'A'+1)%47;
	if(s1==s2)
		cout<<"GO";
	else
		cout<<"STAY";
	return 0;
}
