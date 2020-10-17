#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,ans,m[101],visit[101][201],next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
string a[101];
void dfs(int x,int y)
{
	if(x<1||x>n||y<1||y>m[x]||visit[x][y])
		return;
	visit[x][y]=1;
	for(int i=0; i<=3; i++)
		dfs(x+next[i][0],y+next[i][1]);
}
int main()
{
	string t;
	cin>>n;
	getline(cin,t);
	for(int i=1; i<=n; i++)
	{
		getline(cin,a[i]);
		m[i]=a[i].length()-1;
	}
	for(int i=1; i<=n; i++)
		for(int j=0; j<=m[i]; j++)
			if(!(a[i][j]>='a'&&a[i][j]<='z'))
				visit[i][j]=1;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=m[i]; j++)
			if(!visit[i][j])
			{
				ans++;
				dfs(i,j);
			}
	printf("%d",ans);
	return 0;
}
