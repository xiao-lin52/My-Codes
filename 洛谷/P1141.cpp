#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct bfs
{
	int x;
	int y;
};
bfs a[1000000];
int s[1010][1010],map[1010][1010],visit[1010][1010],next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
	register int n,m,k,l;
	n=read();
	m=read();
	for(register int i=1;i<=n;++i)
	{
		char t;
		for(register int j=1;j<=n;++j)
		{
			cin>>t;
			map[i][j]=t-'0';
		}
	}
	for(register int i=1;i<=m;++i)
	{
		register int head=0,tail=1,sum=1;
		k=read();
		l=read();
		if(!s[k][l])
		{
			a[0].x=k;
			a[0].y=l;
			visit[k][l]=i;
			while(head<tail)
			{
				register int nx,ny;
				for(register int j=0;j<=3;++j)
				{
					nx=a[head].x+next[j][0];
					ny=a[head].y+next[j][1];
					if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&visit[nx][ny]!=i&&map[nx][ny]!=map[a[head].x][a[head].y])
					{
						visit[nx][ny]=i;
						++sum;
						a[tail].x=nx;
						a[tail].y=ny;
						++tail;
					}
				}
				++head;
			}
			for(int i=0;i<tail;i++)
				s[a[i].x][a[i].y]=sum;
		}
		else
			sum=s[k][l];
		printf("%d\n",sum);
	}
	return 0;
}
