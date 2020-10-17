#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,f[100001],dp[100001];
int main()
{
	memset(dp,0x3f,sizeof(dp));
	n=read();
	m=read();
	for(int i=1; i<=m; i++)
		f[read()]=read();
	dp[1]=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=6&&i>=j; j++)
			if(!f[i-j])
				dp[i]=min(dp[i],dp[i-j]+1);
		if(f[i])
			dp[f[i]]=min(dp[i],dp[f[i]]);
	}
	printf("%d",dp[n]);
	return 0;
}

