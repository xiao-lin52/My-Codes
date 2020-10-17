#include<bits/stdc++.h>
using namespace std;
int n,next[8][2]= {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
char ch[105][105];
int print[105][105];
int sta[105][2],top;
char check[10]=" yizhong";
inline void dfs(int x,int y,int step,int f)
{
	sta[++top][0]=x;
	sta[top][1]=y;
	if(step==7)
	{
		for(int i=1; i<=top; ++i)
		{
			print[sta[i][0]][sta[i][1]]=1;
			sta[i][0]=sta[i][1]=0;
		}
		top--;
		return;
	}
	int nx,ny;
	nx=x+next[f][0];
	ny=y+next[f][1];
	if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&ch[nx][ny]==check[step+1])
	{
		dfs(nx,ny,step+1,f);
	}
	sta[top][0]=sta[top][1]=0;
	--top;
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			cin>>ch[i][j];
		}
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(ch[i][j]=='y')
			{
				for(int k=0; k<=7; ++k)
				{
					if(i==9&&j==3&&k==0)
					{
						int fuck=0;
						fuck++;
						fuck--;
					}
					dfs(i,j,1,k);
				}
			}
		}
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(print[i][j])
				cout<<ch[i][j];
			else
				cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}
