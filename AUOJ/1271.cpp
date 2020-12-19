#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,mod=998244353;
int n,m,col,a[N][N],color[N][N],cnt[N*N],p[N*N],f[N*N][2][2],nxt[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
long long ans=1,sum;
char st[N];
int check(int x,int y)
{
	int cnt=0;
	for(int i=0;i<=3;i++)
	{
		int nx=x+nxt[i][0],ny=y+nxt[i][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!a[nx][ny])
			cnt++;
	}
	return cnt;
}
void dfs1(int x,int y)
{
	color[x][y]=col;
	for(int i=0;i<=3;i++)
	{
		int nx=x+nxt[i][0],ny=y+nxt[i][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!color[nx][ny]&&a[nx][ny])
			dfs1(nx,ny);
		if(nx<1||nx>n||ny<1||ny>m)
			p[col]=1;
	}
}
void dfs2(int x,int y)
{
	color[x][y]=1;
	for(int i=0;i<=3;i++)
	{
		int nx=x+nxt[i][0],ny=y+nxt[i][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
			if(a[nx][ny])
				cnt[color[nx][ny]]++;
			else
				if(!color[nx][ny])
					dfs2(nx,ny);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	f[1][0][0]=f[1][1][1]=1;
	for(int i=2;i<=n*m;i++)
	{
		f[i][0][0]=(f[i-1][0][1]+f[i-1][0][0])%mod;
		f[i][0][1]=f[i-1][0][0]%mod;
		f[i][1][0]=(f[i-1][1][1]+f[i-1][1][0])%mod;
		f[i][1][1]=f[i-1][1][0]%mod;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",st+1);
		for(int j=1;j<=m;j++)
		{
			if(st[j]=='#')
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]&&!color[i][j])
			{
				col++;
				dfs1(i,j);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!a[i][j])
			{
				dfs2(i,j);
				goto l;
			}
	l:;
	for(int i=1;i<=col;i++)
	{
		if(p[i])
		{
			sum=(sum+(cnt[i]+1)/2)%mod;
			ans=(ans*(((f[cnt[i]][0][0]+f[cnt[i]][0][1])%mod+(f[cnt[i]][1][0]+f[cnt[i]][1][1])%mod))%mod)%mod;
		}
		else
		{
			sum=(sum+cnt[i]/2)%mod;
			ans=ans*((f[cnt[i]+1][1][1]+f[cnt[i]+1][0][0])%mod)%mod;
		}
	}
	printf("%lld %lld",sum,ans);
	return 0;
}