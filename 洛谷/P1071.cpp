#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string a,b,c;
int visit[26];
char mi[26],yuan[26];
int main()
{
	cin>>a>>b>>c;
	for(int i=0;i<b.length();i++)
		visit[b[i]-'A']=1;
	for(int i=0;i<26;i++)
		if(!visit[i])
		{
			cout<<"Failed";
			return 0;
		}
	for(int i=0;i<a.length();i++)
		if((!visit[b[i]-'A'])&&yuan[b[i]-'A']!=a[i])
		{
			cout<<"Failed";
			return 0;
		}
		else
		{
			mi[a[i]-'A']=b[i];
			yuan[b[i]-'A']=a[i];
			visit[b[i]-'A']=0;
		}
	for(int i=0;i<c.length();i++)
		cout<<mi[c[i]-'A'];
	return 0;
}
