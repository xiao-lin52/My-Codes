#include<iostream>
#include<string>
using namespace std;
int n,m,s;
string t,a[21];
int main()
{
	cin>>n>>m;
	getline(cin,a[0]);
	for(int i=1;i<=n;i++)
	{
	    getline(cin,a[i]);
        if (a[i][a[i].length()-1]!=char(13))
            a[i]+=char(13);
	}
	for(int i=1;i<=m;i++)
	{
		int flag=0;
		getline(cin,t);
        if (t[t.length()-1]!=char(13))
            t+=char(13);
		for(int j=1;j<=n;j++)
			if(t==a[j])
			{
				flag=1;
				break;
			}
		if(flag)
			s++;
	}
	cout<<s;
	return 0;
}
