#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string a,t[9]= {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"," "};
int s;
int main()
{
	getline(cin,a);
	for(int i=0; i<a.length(); i++)
		for(int j=0; j<9; j++)
			for(int k=0; k<t[j].length(); k++)
				if(t[j][k]==a[i]) s+=k+1;
	printf("%d",s);
	return 0;
}
