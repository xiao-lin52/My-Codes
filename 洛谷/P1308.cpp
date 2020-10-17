#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string a,b,c;
int i,q,d,j=-1;
int main()
{
	getline(cin,a);
	getline(cin,b);
	for(i=0;i<a.length();i++)
		if(a[i]>=65&&a[i]<=90)
			a[i]+=32;
	for(i=0;i<b.length();i++)
		if(b[i]>=65&&b[i]<=90)
			b[i]+=32;
	i=0;
	while(i<b.length())
	{
		while(b[i]==' '&&i<b.length())
		{
			i++;
			c="";
		}
		while(b[i]!=' '&&i<b.length())
		{
			c+=b[i];
			i++;
		}
		if(a==c)
		{
			q++;
			if(q==1)
				d=i-a.length();
		}
	}
	if(q!=0)
		printf("%d %d",q,d);
	else
		printf("-1");
	return 0;
}
