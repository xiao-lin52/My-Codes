#include<string>
#include<iostream>
#include<cstring>
using namespace std;
struct bfs
{
	int x;
	int y;
};
bfs a[2501];
int r,c,n,p,visit[51][51];
char map[51][51];
string pos;
int main()
{
	cin>>r>>c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='*')
			{
				a[1].x=i;
				a[1].y=j;
				p=1;
				map[i][j]='.';
			}
		}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>pos;
		int s=0;
		bfs f[2501]={0};
		memset(visit,0,sizeof(visit));
		for(int j=1;j<=p;j++)
		{
			int tx,ty,nx=a[j].x,ny=a[j].y;
			if(pos=="NORTH")
			{
				tx=-1;
				ty=0;
			}
			if(pos=="SOUTH")
			{
				tx=1;
				ty=0;
			}
			if(pos=="WEST")
			{
				tx=0;
				ty=-1;
			}
			if(pos=="EAST")
			{
				tx=0;
				ty=1;
			}
			nx+=tx;
			ny+=ty;
			while(nx<=r&&nx>=1&&ny<=c&&ny>=1&&map[nx][ny]!='X'&&!visit[nx][ny])
			{
				s++;
				f[s].x=nx;
				f[s].y=ny;
				visit[nx][ny]=1;
				nx+=tx;
				ny+=ty;
			}
		}
		p=s;
		memcpy(a,f,sizeof(f));
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
			if(!visit[i][j])
				cout<<map[i][j];
			else
				cout<<'*';
		cout<<endl;
	}
	return 0;
}
