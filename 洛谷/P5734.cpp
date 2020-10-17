#include<iostream>
#include<string>
using namespace std;
string a,t;
int n,op;
void insert_back(string str)
{
	a+=str;
	cout<<a<<endl;
}
void cut(int pos,int len)
{
	string t;
	for(int i=0;i<len;i++)
		t+=a[pos+i];
	a=t;
	cout<<a<<endl;
}
void insert(int pos,string str)
{
	string t1,t2;
	for(int i=0;i<pos;i++)
		t1+=a[i];
	for(int i=pos;i<a.length();i++)
		t2+=a[i];
	a=t1+str+t2;
	cout<<a<<endl;
}
void find(string str)
{
	for(int i=0;i<=a.length()-str.length();i++)
	{
		for(int j=0;j<str.length();j++)
			if(a[i+j]!=str[j])
				goto ctn;
		cout<<i<<endl;
		return;
		ctn:;
	}
	cout<<"-1"<<endl;
}
int main()
{
	cin>>n>>a;
	for(int i=1;i<=n;i++)
	{
		int pos,len;
		string str;
		cin>>op;
		switch(op)
		{
			case 1:
				cin>>str;
				insert_back(str);
				break;
			case 2:
				cin>>pos>>len;
				cut(pos,len);
				break;
			case 3:
				cin>>pos>>str;
				insert(pos,str);
				break;
			case 4:
				cin>>str;
				find(str);
				break;
		}
	}
	return 0;
}
