#include<iostream>
#include<string>
using namespace std;
struct people
{
	int v;
	string job;
};
people a[100100];
int n,m,q,s,p=1;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].v>>a[i].job;
	for(int i=1;i<=m;i++)
	{
		cin>>q>>s;
		if((a[p].v&&!q)||(!a[p].v&&q))
		{
			p+=s;
			if(p>n)
				p-=n;
		}
		else
		{
			p-=s;
			if(p<1)
				p+=n;
		}
	}
	cout<<a[p].job;
	return 0;
}
