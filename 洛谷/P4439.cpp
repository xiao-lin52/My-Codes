#include<iostream>
using namespace std;
int n,s=1;
char a[100];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1])
			s++;
	cout<<s;
	return 0;
}
