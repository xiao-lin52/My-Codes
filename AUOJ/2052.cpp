#include<bits/stdc++.h>
using namespace std;
string a;
int b1,b2,cnt,sum;
int main()
{
	getline(cin,a);
	for(int i=0;i<a.size();i++)
		if(a[i]=='(')
			b1++;
		else
			b2++;
	if(b1-b2!=2&&b2-b1!=2)
	{
		printf("0");
		return 0;
	}
	if(b1-b2==2)
		for(int i=a.size()-1;i>=0;i--)
		{
			if(a[i]==')')
				cnt++;
			else
			{
				cnt--;
				sum++;
			}
			if(cnt==-1)
			{
				printf("%d",sum);
				return 0;
			}
		}
	else
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='(')
				cnt++;
			else
			{
				cnt--;
				sum++;
			}
			if(cnt==-1)
			{
				printf("%d",sum);
				return 0;
			}
		}
	return 0;
}

