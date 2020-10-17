#include<bits/stdc++.h>
using namespace std;
int n,i,ans;
string op[1001];
int main()
{
	cin>>n;
	getchar();
	for(i=1; i<=n; i++)
		getline(cin,op[i]);
	i=1;
	while(i<=n)
	{
		int x=0,j=0;
		string t="";
		ans++;
		if(ans>n)
			break;
		while(!isdigit(op[i][j])&&j<op[i].length())
		{
			t+=op[i][j];
			j++;
		}
		while(isdigit(op[i][j])&&j<op[i].length())
		{
			x=x*10+op[i][j]-'0';
			j++;
		}
		if(t=="goto "&&j==op[i].length())
			i=x;
		else
			i++;
	}
	if(ans>n)
		cout<<"zhe me xiong?!";
	else
		cout<<ans;
	return 0;
}


