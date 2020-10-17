#include<bits/stdc++.h>
using namespace std;
string a;
int cnt,ans;
int main()
{
	getline(cin,a);
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='(')
			cnt++;
		else
			if(cnt)
				cnt--;
			else
			{
				ans++;
				cnt++;
			}
	}
	printf("%d",ans+cnt/2);
	return 0;
}

