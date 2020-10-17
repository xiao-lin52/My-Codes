#include<cstdio>
using namespace std;
int judge(int x,int y)
{
	if(x>=1&&x<=3&&y>=1&&y<=3)
		return 1;
	if(x>=1&&x<=3&&y>=4&&y<=6)
		return 2;
	if(x>=1&&x<=3&&y>=7&&y<=9)
		return 3;
	if(x>=4&&x<=6&&y>=1&&y<=3)
		return 4;
	if(x>=4&&x<=6&&y>=4&&y<=6)
		return 5;
	if(x>=4&&x<=6&&y>=7&&y<=9)
		return 6;
	if(x>=7&&x<=9&&y>=1&&y<=3)
		return 7;
	if(x>=7&&x<=9&&y>=4&&y<=6)
		return 8;
	if(x>=7&&x<=9&&y>=7&&y<=9)
		return 9;
}
int Cal(int x,int y,int num)
{
	if(x==1||x==9||y==1||y==9)
		return num*6;
	if(x==2||x==8||y==2||y==8)
		return num*7;
	if(x==3||x==7||y==3||y==7)
		return num*8;
	if(x==4||x==6||y==4||y==6)
		return num*9;
	return num*10;
}
int flag,sh[10],h[10][10],l[10][10],g[10][10],a[10][10],b[10][10],index[10];
long long ans;
void dfs(int n,int y,long long sum,int s)
{
	int x=index[n];
	while(s==9&&n<=9)
	{
		if(n==9)
		{
			if(sum>ans)
				ans=sum;
			flag=1;
			return;
		}
		n++;
		x=index[n];
		s=sh[x];
		y=1;
	}
	while(a[x][y]&&y<=9)
		y++;
	for(int i=1;i<=9;i++)
		if(!h[x][i]&&!l[y][i]&&!g[b[x][y]][i])
		{
			h[x][i]=l[y][i]=g[b[x][y]][i]=1;
			a[x][y]=i;
			dfs(n,y+1,sum+Cal(x,y,i),s+1);
			a[x][y]=0;
			h[x][i]=l[y][i]=g[b[x][y]][i]=0;
		}
}
int main()
{
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			b[i][j]=judge(i,j);
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j])
			{
				h[i][a[i][j]]=1;
				l[j][a[i][j]]=1;
				g[b[i][j]][a[i][j]]=1;
				sh[i]++;
				ans+=Cal(i,j,a[i][j]);
			}
		}
	int v[10]={0};
	for(int i=1;i<=9;i++)
	{
		int m=-1,mj=0;
		for(int j=1;j<=9;j++)
			if(!v[j]&&sh[j]>m)
			{
				m=sh[j];
				mj=j;
			}
		v[mj]=1;
		index[i]=mj;
	}
	dfs(1,1,ans,sh[index[1]]);
	if(flag)
		printf("%d",ans);
	else
		printf("-1");
	return 0;
}
