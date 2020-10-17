#include<iostream>
#include<string>
using namespace std;
int len1,len2;
string a,t[101];
int main()
{
	cin>>len1>>a;
	for(int i=0;i<len1;i++)
	{
		int flag=1;
		for(int j=0;j<len1-i;j++)
		{
			t[j]+=a[j+i];
			if(a.find(t[j],j+1)!=a.npos)
				flag=0;
		}
		if(flag)
		{
			cout<<i+1;
			break;
		}
	}
	return 0;
}
