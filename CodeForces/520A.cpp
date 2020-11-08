#include<iostream>
using namespace std;
int n,v[26];
char a;
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a;
		if(a>='A'&&a<='Z')
			a+=32;
		if(a>='a'&&a<='z')
			v[a-'a']=1;
	}
	for(int i=0; i<26; i++)
		if(!v[i])
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
	return 0;
}
