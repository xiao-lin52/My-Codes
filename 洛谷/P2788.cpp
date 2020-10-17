#include<iostream>
#include<string>
using namespace std;
string a;
int i,flag;
long long s;
int main()
{
	cin>>a;
	while(a[i]>='0'&&a[i]<='9')
	{
		s=s*10+a[i]-'0';
		i++;
	}
	while(i<a.length())
	{
		switch(a[i])
		{
			case '+':
				flag=1;
				break;
			case '-':
				flag=2;
				break;
		}
		i++;
		int t=0;
		while(a[i]>='0'&&a[i]<='9'&&i<a.length())
		{
			t=t*10+a[i]-'0';
			i++;
		}
		switch(flag)
		{
			case 1:
				s+=t;
				break;
			case 2:
				s-=t;
				break;
		}
	}
	cout<<s;
	return 0;
}
