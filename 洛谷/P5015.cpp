#include<string>
#include<iostream>
using namespace std;
string a;
int sum;
int main()
{
	getline(cin,a);
	for(int i=0;i<a.length();i++)
		if(a[i]!=' ')
			sum++;
	cout<<sum;
	return 0;
}
