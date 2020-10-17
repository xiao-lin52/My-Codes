#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
char x[101],y[101];
int n,p;
int main()
{
	cin>>n>>x>>y;
	for(int i=0;i<n;i++)
		if(y[i]>x[i])
			p=1;
	if(p)
		cout<<"-1";
	else
		cout<<y;
	return 0;
}
