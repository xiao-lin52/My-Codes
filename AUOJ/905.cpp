#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
string s,t,l,r;
int len;
int main()
{
	getline(cin,s);
	getline(cin,t);
	len=s.size();
	for(int i=0;i<len;i++)
		if(t[i]=='L')
			l+=s[i];
		else
			r+=s[i];
	cout<<r;
	for(int i=l.size()-1;i>=0;i--)
		cout<<l[i];
	return 0;
}
