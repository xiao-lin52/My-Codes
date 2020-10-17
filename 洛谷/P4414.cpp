#include<cstdio>
#include<iostream>
using namespace std;
int a[3];
char x,y,z;
int main()
{
	cin>>a[0]>>a[1]>>a[2]>>x>>y>>z;
	if(a[0]>a[1])
		swap(a[0],a[1]);
	if(a[1]>a[2])
		swap(a[1],a[2]);
	if(a[0]>a[1])
		swap(a[0],a[1]);
	cout<<a[x-'A']<<' '<<a[y-'A']<<' '<<a[z-'A'];
	return 0;
}
