#include<cstdio>
#include<iostream>
using namespace std;
int s,t,w,j,a[100];
int main()
{
	cin>>s>>t>>w;
	for(int i=1;i<=w;i++)
	{
		char x;
		cin>>x;
		a[i]=x-'a'+1;
	}
	j=w;
	for(int i=1;i<=5&&a[0]==0;i++)
	{
		while(a[j]==t-w+j&&j)
			j--;
		a[j]++;
		while(j<w)
		{
			j++;
			a[j]=a[j-1]+1;
		}
		for(int i=1;i<=w;i++)
			printf("%c",a[i]+'a'-1);
		printf("\n");
	}
	return 0;
}
