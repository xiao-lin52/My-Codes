#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
using namespace std;
struct node
{
	int x;
	int y;
};
int n,a,b,v[31][31],nxt[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char c[31][31];
long long ans,dis[31][31];
queue<node> q;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=n;j++)
			scanf("%c",&c[i][j]);
	}
	for(int sx=1;sx<=n;sx++)
	{
		for(int sy=1;sy<=n;sy++)
		{
			memset(dis,0x3f,sizeof(dis));
			memset(v,0,sizeof(v));
			dis[sx][sy]=0;
			v[sx][sy]=1;
			q.push(node{sx,sy});
			while(q.size())
			{
				int ux=q.front().x,uy=q.front().y;
				q.pop();
				v[ux][uy]=0;
				for(int i=0;i<=3;i++)
				{
					int vx,vy,w;
					vx=ux+nxt[i][0];
					vy=uy+nxt[i][1];
					if(vx>=1&&vx<=n&&vy>=1&&vy<=n)
					{
						w=c[ux][uy]==c[vx][vy]? a:b;
						if(dis[vx][vy]>dis[ux][uy]+w)
						{
							dis[vx][vy]=dis[ux][uy]+w;
							if(!v[vx][vy])
							{
								v[vx][vy]=1;
								q.push(node{vx,vy});
							}
						}
					}
				}
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ans=max(ans,dis[i][j]);
		}
	}
	printf("%lld",ans);
	return 0;
}
