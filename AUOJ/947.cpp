#include<bits/stdc++.h>
#define ll int
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll t,n,m,s,flag,a[110][1010],sum[8],nxt[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
inline ll dfs(ll x,ll y,ll dir,ll v)
{
	ll cnt=1,nx=x+nxt[dir][0],ny=y+nxt[dir][1];
	if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&a[nx][ny]==v)
		cnt+=dfs(nx,ny,dir,v);
	return cnt;
}
int main()
{
	t=read();
	while(t--)
	{
		flag=0;
		memset(a,0,sizeof(a));
		n=read();
		m=read();
		s=read();
		for(int i=1;i<=m;i++)
		{
			ll x=read(),y=read();
			if(flag)
				continue;
			a[x][y]=i%2+1;
			for(int j=0;j<=7;j++)
				sum[j]=dfs(x,y,j,i%2+1);
			for(int j=0;j<=3;j++)
				if(sum[j]+sum[j+4]-1>=s)
				{
					flag=1;
					break;
				}
			if(flag)
				if(i%2)
					printf("Alice %d\n",i);
				else
					printf("Bob %d\n",i);
		}
		if(!flag)
			printf("draw\n");
	}
	return 0;
}
