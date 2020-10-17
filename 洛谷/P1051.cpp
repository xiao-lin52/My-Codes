#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct price
{
	string name;
	int m;
	int index;
};
bool cmp(price a,price b)
{
	if(a.m!=b.m) return a.m>b.m;
	if(a.index!=b.index) return a.index<b.index;
}
price a[101];
int n,p1,p2,p5,sum;
char p3,p4;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i].index=i;
		cin>>a[i].name>>p1>>p2>>p3>>p4>>p5;
		if(p1>80&&p5>0)
			a[i].m+=8000;
		if(p1>85&&p2>80)
			a[i].m+=4000;
		if(p1>90)
			a[i].m+=2000;
		if(p1>85&&p4=='Y')
			a[i].m+=1000;
		if(p2>80&&p3=='Y')
			a[i].m+=850;
		sum+=a[i].m;
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[1].name<<'\n'<<a[1].m<<'\n'<<sum;
	return 0;
}
