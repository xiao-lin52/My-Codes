#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n;
string a;
int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if((a[a.length()-1]-'0')%2==0)
			printf("even\n");
		else
			printf("odd\n");
	}
	return 0;
}
