#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	int y;
	int step;
	int f;
};
int n,m,d,r,flag,visit[1001][1001][2],nxt[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
queue<node> q;
int main()
{
	scanf("%d%d%d%d",&n,&m,&d,&r);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char x;
			cin>>x;
			if(x=='#')
				visit[i][j][0]=visit[i][j][1]=1;
		}
	q.push(node{1,1,0,0});
	visit[1][1][0]=1;
	while(q.size())
	{
		node t=q.front();
		q.pop();
		if(t.x==n&&t.y==m)
		{
			printf("%d",t.step);
			return 0;
		}
		int nx,ny;
		for(int i=0;i<=3;i++)
		{
			nx=t.x+nxt[i][0];
			ny=t.y+nxt[i][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!visit[nx][ny][t.f])
			{
				visit[nx][ny][t.f]=1;
				q.push(node{nx,ny,t.step+1,t.f});
			}
		}
		nx=t.x+d;
		ny=t.y+r;
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!t.f&&!visit[nx][ny][1])
		{
			visit[nx][ny][1]=1;
			q.push(node{nx,ny,t.step+1,1});
		}
	}
	printf("-1");
	return 0;
}
