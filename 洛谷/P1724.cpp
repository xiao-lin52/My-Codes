#include<string>
#include<iostream>
using namespace std;
string a;
int t,x,y,len;
int main()
{
	cin>>a>>t;
	len=a.length();
	for(int i=0;i<len;i++)
		switch(a[i])
		{
			case 'E':
				x+=1;
				break;
			case 'S':
				y-=1;
				break;
			case 'W':
				x-=1;
				break;
			case 'N':
				y+=1;
				break;
		}
	x*=t/len;
	y*=t/len;
	t%=len;
	for(int i=0;i<t;i++)
		switch(a[i])
		{
			case 'E':
				x+=1;
				break;
			case 'S':
				y-=1;
				break;
			case 'W':
				x-=1;
				break;
			case 'N':
				y+=1;
				break;
		}
	cout<<x<<" "<<y;
	return 0;
}
