#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
char op;
string fa;
map<string,string> f;
string find(string x)
{
	if(f[x]=="")
		return x;
	else
		return f[x]=find(f[x]);
}
int main()
{
	while(cin>>op&&op!='$')
	{
		string x;
		cin>>x;
		switch(op)
		{
			case '#':
				fa=x;
				break;
			case '+':
				f[find(x)]=find(fa);
				break;
			case '?':
				cout<<x<<" "<<find(x)<<endl;
				break;
		}
	}
	return 0;
}
