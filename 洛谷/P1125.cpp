#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string s;
int maxn,minn=101,a[26];
bool prime(int n)
{
	if(n==1||n==0) return false;
	for(int i=2;i<n;i++)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)
		a[s[i]-'a']++;
	for(int i=0;i<26;i++)
		if(a[i])
		{
			maxn=max(maxn,a[i]);
			minn=min(minn,a[i]);
		}
	if(prime(maxn-minn))
		cout<<"Lucky Word"<<endl<<maxn-minn;
	else
		cout<<"No Answer"<<endl<<"0";
	return 0;
}
