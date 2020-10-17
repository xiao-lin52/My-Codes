#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
struct people
{
	string s;
	int y;
	int m;
	int d;
	int sx;
};
people a[100];
int n;
bool cmp(people i,people j)
{
	if(i.y!=j.y) return i.y<j.y;
	if(i.m!=j.m) return i.m<j.m;
	if(i.d!=j.d) return i.d<j.d;
	return i.sx>j.sx;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].s>>a[i].y>>a[i].m>>a[i].d;
		a[i].sx=i+1;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
		cout<<a[i].s<<endl;
	return 0;
}
