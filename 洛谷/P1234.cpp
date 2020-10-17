#include<iostream>
using namespace std;
int n,m,ans;
char a[1001][1001],cnm;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
//		scanf("%c",&cnm); 
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j>=4&&a[i][j]=='h'&&a[i][j-1]=='e'&&a[i][j-2]=='h'&&a[i][j-3]=='e')
				ans++;
			if(i>=4&&a[i][j]=='h'&&a[i-1][j]=='e'&&a[i-2][j]=='h'&&a[i-3][j]=='e')
				ans++;
			if(j<=m-3&&a[i][j]=='h'&&a[i][j+1]=='e'&&a[i][j+2]=='h'&&a[i][j+3]=='e')
				ans++;
			if(i<=n-3&&a[i][j]=='h'&&a[i+1][j]=='e'&&a[i+2][j]=='h'&&a[i+3][j]=='e')
				ans++;
		}
	cout<<ans;
	return 0;
}
