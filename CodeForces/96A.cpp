#include<bits/stdc++.h>
using namespace std;
string a;
int s=1;
int main()
{
	cin>>a;
	for(int i=1;i<a.length();i++)
	{
		if(a[i]==a[i-1])
			s++;
		else
			s=1;
		if(s>=7)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}
