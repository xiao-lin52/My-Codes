#include<bits/stdc++.h>
using namespace std;
string a;
int sum;
int main()
{
	getline(cin,a);
	for(int i=0;i<a.size();i++)
		if(isdigit(a[i])||isalpha(a[i]))
			sum++;
	printf("%d",sum);
	return 0;
}