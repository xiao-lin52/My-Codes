#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string a;
int i,p=-1,v=1,len;
double x,c;
char w;
int main()
{
	cin>>a;
	len=a.length();
	while(i<len)
	{
			if(a[i]=='+')
			{
				v=1;
				i++;
			}
			if(a[i]=='-')
			{
				v=-1;
				i++;
			}
			if(a[i]=='=')
			{
				v=1;
				p=1;
				i++;
			}
			int temp=0;
			while(a[i]>='0'&&a[i]<='9'&&i<len)
				temp=temp*10+a[i++]-'0';
			if(a[i]>='a'&&a[i]<='z')
			{
				if(a[i-1]<'0'||a[i-1]>'9')
					temp=1;
				x+=temp*p*v;
				w=a[i];
				i++;
			}
			else
				c+=temp*(0-p)*v;
	}
	printf("%c=%.3lf",w,c/x);
	return 0;
}
