#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	register ll x=0,f=1;
	register char ch=getchar();
	while(!isdigit(ch)) { if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll n,m,q,a[80][80],nr[80][80],dp[80][80][80][80];
int main()
{
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%1lld",&a[i][j]);
			if(!a[i][j])
				nr[i][j]=nr[i][j-1]+1;
		}
	for(ll k=1;k<=n;k++)
		for(ll l=1;l<=m;l++)
			for(ll i=1;i<=k;i++)
				for(ll j=1;j<=l;j++)
				{
					ll minn=0x3f3f3f3f;
					for(ll p=k;p>=i&&!a[p][l];p--)
					{
						minn=min(minn,min(nr[p][l],l-j+1));
						dp[i][j][k][l]+=minn;
					}
					dp[i][j][k][l]+=dp[i][j][k-1][l]+dp[i][j][k][l-1]-dp[i][j][k-1][l-1];
				}
	while(q--)
	{
		ll x1=read(),y1=read(),x2=read(),y2=read();
		printf("%lld\n",dp[x1][y1][x2][y2]);
	}
	return 0;
}
