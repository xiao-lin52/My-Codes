#include<iostream>
#include<string>
using namespace std;
string a;
int p1,p2,p3;
bool check(int i)
{
	if(a[i]=='-'&&a[i-1]!='-'&&a[i+1]!='-'&&i+1<a.length()&&i-1>=0)
	{
		if((a[i-1]>='a'&&a[i-1]<='z')&&(a[i+1]>='a'&&a[i+1]<='z')&&a[i+1]>a[i-1])
			return true;
		if((a[i-1]>='0'&&a[i-1]<='9')&&(a[i+1]>='0'&&a[i+1]<='9')&&a[i+1]>a[i-1])
			return true;
	}
	return false;
}
void print(int i)
{
	if(a[i-1]>='a'&&a[i-1]<='z')
	{
		if(p1==1)
			if(p3==1)
				for(char j=a[i-1]+1;j<=a[i+1]-1;j++)
					for(int k=1;k<=p2;k++)
						cout<<j;
			else
				for(char j=a[i+1]-1;j>=a[i-1]+1;j--)
					for(int k=1;k<=p2;k++)
						cout<<j;
		if(p1==2)
			if(p3==1)
				for(char j=a[i-1]+1-32;j<=a[i+1]-1-32;j++)
					for(int k=1;k<=p2;k++)
						cout<<j;
			else
				for(char j=a[i+1]-1-32;j>=a[i-1]+1-32;j--)
					for(int k=1;k<=p2;k++)
						cout<<j;
	}
	else
		if(p1==1||p1==2)
			if(p3==1)
				for(char j=a[i-1]+1;j<=a[i+1]-1;j++)
					for(int k=1;k<=p2;k++)
						cout<<j;
			else
				for(char j=a[i+1]-1;j>=a[i-1]+1;j--)
					for(int k=1;k<=p2;k++)
						cout<<j;
	if(p1==3)
		for(char j=a[i-1]+1;j<=a[i+1]-1;j++)
			for(int k=1;k<=p2;k++)
				cout<<"*";
}
int main()
{
	cin>>p1>>p2>>p3>>a;
	for(int i=0;i<a.length();i++)
		if(check(i))
			print(i);
		else
			cout<<a[i];
	return 0;
}
