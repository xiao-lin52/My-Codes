#include<iostream>
#include<string>
using namespace std;
string a;
int x[2],fx[2],h[4][2],l[4][2],xy[10][2]={{0,0},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}};
int main()
{
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		h[xy[a[i]-'0'][0]][i%2]++;
		l[xy[a[i]-'0'][1]][i%2]++;
		if(a[i]-'0'==3||a[i]-'0'==5||a[i]-'0'==7)
			x[i%2]++;
		if(a[i]-'0'==1||a[i]-'0'==5||a[i]-'0'==9)
			fx[i%2]++;
		if(h[1][i%2]==3||h[2][i%2]==3||h[3][i%2]==3||l[1][i%2]==3||l[2][i%2]==3||l[3][i%2]==3||x[i%2]==3||fx[i%2]==3)
		{
			if(i%2==0)
				cout<<"xiaoa wins.";
			else
				cout<<"uim wins.";
			return 0;
		}
	}
	cout<<"drew.";
	return 0;
}
