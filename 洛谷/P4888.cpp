#include<cstdio>
#include<iostream>
using namespace std;
int l,q;
char a[2001][2001];
int check(int x,int y,int x1,int y1)
{
	if(x1>=1&&x1<=l&&y1>=1&&y1<=l&&x>=1&&x<=l&&y>=1&&y<=l&&a[x][y]==a[x1][y1])
		return 1;
	else
		return 0;
}
int count(int x,int y,int dir)
{
	int sum=1,x1=x,y1=y,direction[2][2]={{-1,0},{0,1}};
	while(check(x,y,x1,y1))
	{
		x+=direction[dir][0];
		y+=direction[dir][1];
		x1-=direction[dir][0];
		y1-=direction[dir][1];
		if(check(x,y,x1,y1))
			sum+=2;
	}
	return sum;
}
int main()
{
	scanf("%d%d",&l,&q);
	for(int i=1;i<=l;i++)
		for(int j=1;j<=l;j++)
			cin>>a[i][j];
	for(int i=1;i<=q;i++)
	{
		int x,y,sum=0;
		scanf("%d%d",&x,&y);
		for(int i=0;i<=1;i++)
			sum=count(x,y,i)>sum? count(x,y,i):sum;
		printf("%d\n",sum);
	}
	return 0;
}
