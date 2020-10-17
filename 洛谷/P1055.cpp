#include<string>
#include<iostream>
using namespace std;
string a;
int s,i,k;
int main()
{
	getline(cin,a);
	while(i<12)
	{
		while(a[i]>='0'&&a[i]<='9'&&i<12)
		{
			k++;
			s+=(a[i++]-'0')*k;
		}
		i++;
	}
	if(s%11+'0'==a[12]&&s%11!=10)
		cout<<"Right";
	else
		if(s%11==10&&a[12]=='X')
			cout<<"Right";
		else
		{
			if(s%11!=10)
				a[12]=s%11+'0';
			else
				a[12]='X';
			cout<<a;
		}
	return 0;
}
