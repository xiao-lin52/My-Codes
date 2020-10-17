#include<bits/stdc++.h>
using namespace std;
string s;
long long maxn,ans,b[63];
long double l;
long long my_log(long double x)
{
	long long s=0;
	while(x>1)
	{
		s++;
		x/=2;
	}
	return s;
}
int main()
{
	cin>>s>>l;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
			b[s[i]-'A'+1]++;
		if(s[i]>='a'&&s[i]<='z')
			b[s[i]-'a'+27]++;
		if(s[i]>='0'&&s[i]<='9')
			b[s[i]-'0'+53]++;
	}
	for(int i=1;i<=62;i++)
		maxn=max(maxn,b[i]);
	cout<<my_log((l-s.length()+maxn)*1.0/maxn);
	return 0;
}
