#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
struct node
{
	int x;
	int y;
	int blood;
	int time;
};
char a[301][301];
long long p,r,c,n,m,ans=0x3f3f3f3f,vis[301][301],nxt[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
void bfs()
{
	queue<node> q;
	q.push(node{1,1,p,0});
	vis[1][1]=1;
	while(q.size())
	{
		node u=q.front();
		q.pop();
		if(u.blood<=0)
			continue;
		if(u.x==n&&u.y==m)
		{
			ans=ans<u.time? ans:u.time;
			continue;
		}
		for(int i=0;i<=3;i++)
		{
			int nx=u.x+nxt[i][0],ny=u.y+nxt[i][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&a[nx][ny]!='x')
				switch(a[nx][ny])
				{
					case 'A':
						vis[nx][ny]=1;
						q.push(node{nx,ny,u.blood-r,u.time+1});
						break;
					case 'D':
						vis[nx][ny]=1;
						q.push(node{nx,ny,u.blood+c,u.time+1});
						break;
					default:
						vis[nx][ny]=1;
						q.push(node{nx,ny,u.blood,u.time+1});
				}
		}
	}
}
int main()
{
	cin>>p>>r>>c>>n>>m;
	for(long long i=1; i<=n; i++)
		for(long long j=1; j<=m; j++)
			cin>>a[i][j];
	bfs();
	if(ans==0x3f3f3f3f)
		cout<<"jie cao ne???";
	else
		cout<<ans;
	return 0;
}

