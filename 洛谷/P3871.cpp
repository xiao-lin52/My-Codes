#include<bits/stdc++.h>
#define re register int
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if (ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int n,m,dp[100001][21];
int main()
{
	n=read();
	m=read();
	for(re i=1;i<=n;i++)
		dp[i][0]=read();
	for(re j=1;(1<<j)<=n;j++)
		for(re i=1;i+(1<<j)-1<=n;i++)
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
	for(re i=1;i<=m;i++)
	{
		re l,r,k;
		l=read();
		r=read();
		k=log(r-l+1.0)/log(2.0);
		printf("%d\n",max(dp[l][k],dp[r-(1<<k)+1][k]));
	}
	return 0;
}
